#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

void* block(int *n)
{
	int i, m, flag =0;
	m = *n/2;
	for(i=2; i<=m; i++)
	{
		if (*n%i==0)
		{
			printf("Not prime\n");
			flag = 1;
			break;
		}
	}
	if (flag==0)
	printf("Prime\n");	
}

int num = 3;
void* thread_return;

int main()
{
	pthread_t thread1;
	
	pthread_create(&thread1, NULL, (void*)block, &num);
	pthread_join(thread1, &thread_return);
	
	printf("Done %s\n", (char*)thread_return);
	return 0;
}