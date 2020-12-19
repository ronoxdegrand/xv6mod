#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc,char *argv[])
{
	int first = atoi(argv[1]);
	int second = atoi(argv[2]);
    int status = set_priority(first, second);
	printf(1, "Status %d \n", status);
 	exit();
}