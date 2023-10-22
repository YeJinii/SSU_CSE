#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char * argv[])
{
	int procnum=0;

	procnum=get_num_proc();
	printf(1,"Total Number of Active Processes: %d\n", procnum);
    exit();
}
