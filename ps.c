#include "ProcessInfo.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main(void)
{
	enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
	static char *states[] = {
  		[UNUSED]    "UNUSED  ",
  		[EMBRYO]    "EMBRYO  ",
  		[SLEEPING]  "SLEEPING",
  		[RUNNABLE]  "RUNNABLE",
  		[RUNNING]   "RUNNING ",
  		[ZOMBIE]    "ZOMBIE  "
  		};

	struct ProcessInfo processInfoTable[NPROC];
	int numbers = getprocs(processInfoTable);
	printf(1, "pid state name priority rtime wtime\n");
	for (int i = 0; i < numbers; i++)
	{
		printf(1, "%d ", processInfoTable[i].pid);
		printf(1, "%s",states[processInfoTable[i].state]);
		printf(1, " %s", processInfoTable[i].name);
        printf(1," %d",processInfoTable[i].priority);
		printf(1," %d",processInfoTable[i].rtime);
		printf(1," %d", (processInfoTable[i].etime - processInfoTable[i].ctime) - processInfoTable[i].rtime);
		printf(1, "\n");
	}
	exit();
}