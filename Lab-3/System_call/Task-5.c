#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid, id1, id2, id;
	id = fork();
	
	if (id<0)
	{
		printf("The code has issues. \n");
	}
	else if (id==0)
	{	
		id1 = fork();
		id2 = fork();
		if (id1<0 || id2 <0)
		{
			printf("The code has issues. \n");
		}
		else if (id1 == 0)
		{
			id1 = getpid();
			printf("Grand Child process ID: %d\n", id1);
		}
		else if (id2 == 0)
		{
			id2 = getpid();
			printf("Grand Child process ID: %d\n", id2);
		}
		else
		{
			id = getpid();
			printf("Child process ID: %d\n", id);
		}
	}
	else
	{	
		pid = getpid();
		printf("Parent process ID: %d\n", pid);
	}
	return 0;
}