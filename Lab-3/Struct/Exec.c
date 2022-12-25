#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	printf("Program-2 Running...");
	pid_t pid, status;
	pid = fork();
	if(pid == 0)
	{		
		execl("Downloads/CSE321/Lab-3/Struct", "Program-1", "hia1", "hia2", NULL);
	}
	else if(pid>0)
	{
		wait(&status);
		execl("bin/pwd/","pwd", NULL);
	}
}