#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "processInfo.h"
int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_hello(void){
	cprintf("helloxv6\n");
	return 0;
}

int
sys_hello_name(void){
	char * name;
	argstr(0,&name);
	cprintf("hello %s\n", name);
	return 0;
}

int
sys_get_num_proc(void){
	int procnum=0;
	procnum=getnumproc();
	return procnum;
}

int
sys_get_max_pid(void){
	int maxpid=0;
	maxpid = getmaxpid();
	return maxpid;
}

int
sys_get_proc_info(void){
	int ret=0;
	int pid=0;
	int p=0;
	argint(0,&pid);
	argint(1,&p);
	//struct processInfo *pp = (struct processInfo*)p;
	ret=getprocinfo(pid,p);
	return ret;
}

int sys_set_prio(void){
	int nice=0;
	argint(0, &nice);
	int ret=0;
	ret=setprio(nice);
	return ret;
}

int
sys_get_prio(void){
	int nice=0;
	nice = getprio();
	return nice;
}
