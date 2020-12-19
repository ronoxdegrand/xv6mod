#ifndef _PROCESSINFO_H_
#define _PROCESSINFO_H_
#include "types.h"

struct ProcessInfo{
	int pid;
	int ppid;
	int state;
	char name[16];
    int priority;
	int etime, ctime, rtime;
};
#endif