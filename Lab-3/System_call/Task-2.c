#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t id, id1;
	id = fork();
	
	if (id<0)
	{
		printf("The code has issues. \n");
	}
	else if (id==0)
	{
		id1 = fork();
		
		if (id1 < 0)
		{
			printf("The code has issues. \n");
		}
		
		else if (id1 == 0)
		{
			printf("I am grandchild\n");
		}
		else
		{
			wait(NULL);
			printf("I am child\n");
		}
	}
	else
	{	
		wait(NULL);
		printf("I am parent\n");
	}
	return 0;
}