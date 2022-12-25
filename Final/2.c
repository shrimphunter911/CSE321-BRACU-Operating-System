#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<pthread.h>
#include<stdbool.h>

int main()
{
	pid_t id, id1;
	int z = getpid();
	id= fork();
	if (id<0)
	{
		printf("Problem\n");
	}
	else if (id==0)
	{	
		int x = getpid();
		id1 = fork();
		if (id1 <0)
		{
			printf("Problem\n");
		}
		else if (id1==0)
		{
			int y = getpid();
			if (y%2 != 0)
			{
				printf("%d saying goodbye\n", y);
			}
			else
			{
				printf("Hello I am %d, child of %d, grandchild of %d\n", y, x, z);
			}
		}
		else
		{
			wait(NULL);	
		}
	}
	else
	{
		wait(NULL);
	}
	return 0;
}
