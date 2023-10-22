#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "processInfo.h"

int main(int argc, char * argv[])
{
	printf(1,"%s      %s     %s         %s", "PID", "PPID", "SIZE", "Number of Context Switch\n");
    
	struct processInfo *p = malloc(sizeof(struct processInfo));
	int mpid = get_max_pid();

	for(int i=1; i<=mpid; i++){
		int ret=0;
		ret=get_proc_info(i,p);
		if(ret==-1) continue;
		else
		{
			if(i==1){
				printf(1,"%d        %d        %d        %d\n", i, 0, p->psize, p->numberContextSwitches);
			}
			else{
			printf(1,"%d        %d        %d        %d\n", i, p->ppid, p->psize, p->numberContextSwitches);
			}
		}
	}
	exit();
}
