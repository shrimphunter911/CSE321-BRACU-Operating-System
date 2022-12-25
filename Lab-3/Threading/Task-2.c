#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

int var = 1;
void* block(void* arg)
{
	int *thread = (int*)arg;
	for(int i=0; i<5; i++)
	{
		printf("Thread %d prints %d\n", *thread, var);
		var++;
	}
	return NULL;
}

int main()
{
	pthread_t thread[5];
	for (int i = 0; i<5; i++)
	{
		pthread_create(&thread[i], NULL, block, (void*)&i);
		pthread_join(thread[i], NULL);
	}
}