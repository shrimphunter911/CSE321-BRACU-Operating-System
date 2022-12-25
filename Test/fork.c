#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>
main()
{
	pid_t pid;
	pid = fork();
	if (pid == 0)
		printf("\n I'm the child process \n");
	else if (pid > 0)
		printf("\n I'm the parent process. My child pid is %d", pid);
	else
		perror("error in fork");
}