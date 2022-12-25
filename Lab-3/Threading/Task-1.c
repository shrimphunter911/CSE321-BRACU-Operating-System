#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

int var = 0;
void* block(void* arg)
{
	var++;
}

int main()
{
	pthread_t thread[5];
	for (int i = 0; i<5; i++)
	{
		pthread_create(&thread[i], NULL, block, NULL);
		pthread_join(thread[i], NULL);
		printf("Thread-%d running\n", i+1);
		printf("Thread-%d closed\n", i+1);
	}
}