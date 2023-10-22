#include "ssufs-ops.h"

extern struct filehandle_t file_handle_array[MAX_OPEN_FILES];

int ssufs_allocFileHandle() {
	for(int i = 0; i < MAX_OPEN_FILES; i++) {
		if (file_handle_array[i].inode_number == -1) {
			return i;
		}
	}
	return -1;
}

int ssufs_create(char *filename){
	/* 1 */
	struct inode_t *tmp = (struct inode_t *) malloc(sizeof(struct inode_t));

	int inodenum=0;

	//allocInode를 통해 파일을 저장할 공간이 있는지 확인
	if((inodenum=ssufs_allocInode())<0){//성공시 inode number을 리턴
		//fprintf(stderr, "alloc Inode failed\n");
		return -1;
	}

	ssufs_readInode(inodenum, tmp);
	tmp->status=INODE_IN_USE; //inode 사용중
	strcpy(tmp->name, filename); //인자로 불러온 파일 이름 inode에 저장
	tmp->file_size=0; //file size 초기화 (create 했으니까)
	//memset(tmp->direct_blocks, 0, MAX_FILE_SIZE); //file목록 배열 초기화

	ssufs_writeInode(inodenum, tmp); //inode 정보 쓰기
	return 0;
}


void ssufs_delete(char *filename){
	/* 2 */
	int inodenum=open_namei(filename);
	ssufs_freeInode(inodenum);
	for(int i=0; i<MAX_OPEN_FILES; i++){
		if(file_handle_array[i].inode_number == inodenum){
			file_handle_array[i].inode_number=-1;
		}
	}
}

int ssufs_open(char *filename){
	
	int inodenum=open_namei(filename);
	//struct filehandle_t *tmp = (struct filehandle_t *) malloc(sizeof(struct filehandle_t));
	int file_handle=0;
	if((file_handle=ssufs_allocFileHandle())<0){
		//fprintf(stderr, "file handle alloc error.\n");
		return -1;
	}

	file_handle_array[file_handle].offset=0;
	file_handle_array[file_handle].inode_number=inodenum;

	return file_handle;

}

void ssufs_close(int file_handle){
	file_handle_array[file_handle].inode_number = -1;
	file_handle_array[file_handle].offset = 0;
}

int ssufs_read(int file_handle, char *buf, int nbytes){
	/* 4 */
	char *tmpbuf = (char *)malloc(sizeof(char) * BLOCKSIZE * MAX_FILE_SIZE);
	char *blockbuf = (char *)malloc(sizeof(char) * BLOCKSIZE);
	memset(tmpbuf, 0, sizeof(tmpbuf));
	memset(blockbuf, 0, sizeof(blockbuf));

	int offset = file_handle_array[file_handle].offset;

	struct inode_t *tmp = (struct inode_t *) malloc(sizeof(struct inode_t)); 
	ssufs_readInode(file_handle_array[file_handle].inode_number, tmp);

	int file_size = tmp->file_size;
	int to_read_block=file_size/BLOCKSIZE;
	
	if((offset+nbytes)>file_size){
		return -1;
	}

	if(file_size%BLOCKSIZE==0&&file_size!=0){
		to_read_block--;
	}
	if(file_size==0){
		to_read_block=-1;
	}

	for(int i=0; i<=to_read_block; i++){
		//memset(blockbuf, 0, sizeof(blockbuf));
		ssufs_readDataBlock(tmp->direct_blocks[i], blockbuf);
		strcpy(tmpbuf+strlen(tmpbuf), blockbuf);
	}
	
	//요청한 바이트수만큼 buf에 저장	
	strncpy(buf, tmpbuf+offset, nbytes);
	//inode 정보 변경
	file_handle_array[file_handle].offset = offset+nbytes;
	return 0;
}

int ssufs_write(int file_handle, char *buf, int nbytes){
	/* 5 */
	int offset = file_handle_array[file_handle].offset;
	struct inode_t *inode = (struct inode_t *) malloc(sizeof(struct inode_t));
	ssufs_readInode(file_handle_array[file_handle].inode_number, inode);

	char *tmpbuf = (char *)malloc(sizeof(char) * BLOCKSIZE * MAX_FILE_SIZE);
	char *blockbuf = (char *)malloc(sizeof(char) * BLOCKSIZE);
	memset(tmpbuf, 0, sizeof(tmpbuf));
	memset(blockbuf, 0, sizeof(blockbuf));

	int file_size = inode->file_size;//inode에서 파일 사이즈를 가져옴
	int final_file_size= offset+nbytes;

	if(final_file_size>BLOCKSIZE*MAX_FILE_SIZE){//최대 파일크기 제한 초과
		return -1;
	}

	int to_read_block=file_size/BLOCKSIZE;
	if(file_size%BLOCKSIZE==0&&file_size!=0){//한페이지를 전부 다 쓰는 경우 ex) 64byte, 128byte
			to_read_block--;
	}

	if(file_size==0){
		to_read_block=-1;
	}

	if(file_size>=(final_file_size)){//덮어쓰기

		for(int i=0; i<=to_read_block; i++){//tmpbuf에 블록별로 저장되어있는 내용을 붙임
			memset(blockbuf, 0, sizeof(blockbuf));
			ssufs_readDataBlock(inode->direct_blocks[i], blockbuf);
			strcpy(tmpbuf+strlen(tmpbuf), blockbuf);
		}

		for(int i=0; i<=to_read_block; i++){//다시 갱신한 내용을 업데이트
			ssufs_writeDataBlock(inode->direct_blocks[i], tmpbuf+BLOCKSIZE*i);
		}
		file_handle_array[file_handle].offset=offset+nbytes;
		return 0;
	}
	else{//블록을 추가 할당해야 함

		int to_upload_block = final_file_size/BLOCKSIZE; //할당해야하는 블록의 수 0개(1) 1개(2) 2개(3) 3개(4)

		if(final_file_size%BLOCKSIZE==0){
			to_upload_block--;
		}

		if(to_upload_block>=MAX_FILE_SIZE){
			return -1;
		}

		for(int i=0; i<=to_read_block; i++){//tmpbuf에 블록별로 저장되어있는 내용을 붙임
			memset(blockbuf, 0, sizeof(blockbuf));
			ssufs_readDataBlock(inode->direct_blocks[i], blockbuf);
			strcpy(tmpbuf+strlen(tmpbuf), blockbuf);
		}

		strncpy(tmpbuf+offset, buf, nbytes);

		int updateblock[4]={0,0,0,0};

		//먼저 할당이 되는지부터 확인하자
		for(int i=0; i<=to_upload_block; i++){
			if(inode->direct_blocks[i]==-1){//할당이 안돼있어요!
				if((inode->direct_blocks[i]=ssufs_allocDataBlock())<0){//할당 실패니까 원상태로 돌려놔야해!
					for(int u=0; u<4; u++){
						if(updateblock[u]==1){//update한 흔적이 있으면
							//다시 free
							ssufs_freeDataBlock(inode->direct_blocks[u]);
							inode->direct_blocks[u]=-1;
						}
					}
					return -1;
				}
				else {//할당 가능하고 이미 할당함
					updateblock[i]=1;					
				}
			}
		}

		for(int i=0; i<=to_upload_block; i++){
			ssufs_writeDataBlock(inode->direct_blocks[i],tmpbuf+BLOCKSIZE*i);
		}
		inode->file_size= final_file_size;
		ssufs_writeInode(file_handle_array[file_handle].inode_number, inode);
		file_handle_array[file_handle].offset=offset+nbytes;
		return 0;
	}
}

int ssufs_lseek(int file_handle, int nseek){
	int offset = file_handle_array[file_handle].offset;

	struct inode_t *tmp = (struct inode_t *) malloc(sizeof(struct inode_t));
	ssufs_readInode(file_handle_array[file_handle].inode_number, tmp);
	
	int fsize = tmp->file_size;
	
	offset += nseek;

	if ((fsize == -1) || (offset < 0) || (offset > fsize)) {
		free(tmp);
		return -1;
	}

	file_handle_array[file_handle].offset = offset;
	free(tmp);

	return 0;
}
