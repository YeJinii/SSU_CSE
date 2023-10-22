#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <malloc.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

/* Splits the string by space and returns the array of tokens
 *
 */
char **tokenize(char *line)
{
	char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
	char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
	int i, tokenIndex = 0, tokenNo = 0;

	for(i =0; i < strlen(line); i++){

		char readChar = line[i];

		if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
			token[tokenIndex] = '\0';
			if (tokenIndex != 0){
				tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
				strcpy(tokens[tokenNo++], token);
				tokenIndex = 0; 
			}
		} else {
			token[tokenIndex++] = readChar;
		}
	}

	free(token);
	tokens[tokenNo] = NULL ;
	return tokens;
}

int main(int argc, char* argv[]) {
	char  line[MAX_INPUT_SIZE];            
	char  **tokens;              
	int i;

	FILE* fp;
	if(argc == 2) { //인자가 두개일 때 두번째 인자 파일을 읽기 전용으로 오픈
		fp = fopen(argv[1],"r");
		if(fp < 0) { //파일오픈 에러시 에러 처리
			printf("File doesn't exists.");
			return -1;
		}
	}

	char *path;
	path = getenv("PATH");
	char pwd[1024];
	memset(pwd, '\0', 1024);
	getcwd(pwd,1024);
	sprintf(path, "%s:%s", path, pwd);
	setenv("PATH", path, 1);
	
	while(1) {	 //무한루프		
		/* BEGIN: TAKING INPUT */
		bzero(line, sizeof(line)); //line 배열을 0으로 채움
		//인자 2개 입력시
		if(argc == 2) { // batch mode
			//두번째 인자에 저장 되어 있는 파일에서 한줄을 읽어옴
			if(fgets(line, sizeof(line), fp) == NULL) { // file reading finished
				//읽어올 내용이 없으면 break
				break;	
			}
			line[strlen(line) - 1] = '\0';//한줄씩 읽어오면서 맨끝에 개행 지움
		} else { // interactive mode
			printf("$ ");
			scanf("%[^\n]", line); //개행 입력시까지 문자열 받음
			getchar(); //개행 입력 받기
		}
		//printf("Command entered: %s (remove this debug output later)\n", line);
		/* END: TAKING INPUT */

		line[strlen(line)] = '\n'; //terminate with new line
		tokens = tokenize(line);

		//do whatever you want with the commands, here we just print them
		int tcnt=0;
		for(i=0;tokens[i]!=NULL;i++){
			//printf("found token %s (remove this debug output later)\n", tokens[i]);
			tcnt++;			
		}
		//printf("tcnt : %d\n", tcnt);
		int pcnt=1;
		for(int i=0; i<tcnt; i++){
			if(tokens[i][0]=='|'){
				pcnt++;
			}
		}
		//printf("pcnt : %d\n", pcnt);

		char ***ftokens; 
		ftokens= (char ***)malloc(pcnt*sizeof(char**));
		for(int i=0; i<pcnt; i++){
			*(ftokens+i) = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
			for(int j=0; j< MAX_NUM_TOKENS; j++){
				*(*(ftokens+i)+j) = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
			}
		}
			
		int p=0,t=0;//pipe,token
		for(int i=0; i<tcnt; i++){
			if(tokens[i][0]!='|'){
				strcpy(ftokens[p][t],tokens[i]);
				ftokens[p][t][strlen(tokens[i])]='\0';
				//printf("%s 를 저장함 ", ftokens[p][t]);
				t++;
			}
			else if(tokens[i][0]=='|'){ //파이프인경우
				ftokens[p][t]=NULL;
				p++;
				t=0;
			}
		}
		ftokens[p][t]=NULL;
		ftokens[p+1]=NULL;
		if(pcnt==1){//명령어에 파이프가 없을때
			pid_t pid;
			if((pid=fork())<0)
			{				
				fprintf(stderr, "fork error\n");
				exit(1);
			}
			else if(pid==0)
			{ //자식프로세스 일때 
				if(execvp(tokens[0],tokens)==-1){
					fprintf(stderr, "SSUShell : Incorrect command\n");
					exit(1);
				}
				exit(1);
			}
			else{//부모프로세스 일때 
				wait(NULL); 
			}
		}
		else{//파이프 명령어 일때
			int pipe_fd[2];
			pid_t pid;
			int fd_in=0;
			char ***cmd=ftokens;
			while(*cmd!=NULL){
				pipe(pipe_fd);
				if((pid=fork())<0)
				{				
					fprintf(stderr, "fork error\n");
					exit(1);
				}
				else if(pid==0)
				{ //자식프로세스 일때 
					dup2(fd_in, 0);
					if(*(cmd+1)!=NULL){
						dup2(pipe_fd[1],1);
					}
					close(pipe_fd[0]);
					if(execvp((*cmd)[0],*cmd)==-1){
						fprintf(stderr, "SSUShell : Incorrect command\n");
						exit(1);
					}
					exit(1);
				}
				else{//부모프로세스 일때 
					wait(NULL); 
					close(pipe_fd[1]);
					fd_in=pipe_fd[0];
					cmd++;
				}
			}
		}


		// Freeing the allocated memory	
		for(i=0;tokens[i]!=NULL;i++){
			free(tokens[i]);
		}
		free(tokens);

	}
	return 0;
}

