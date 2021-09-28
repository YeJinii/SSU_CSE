#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char * argv[])
{
	int maxpid=0;

	maxpid=get_max_pid();
	printf(1,"Maximum PID: %d\n", maxpid);
    exit();
}
