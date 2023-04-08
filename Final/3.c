#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<pthread.h>
#include<stdbool.h>

int arr[5] = {10, 20, 30, 40, 50};
void* sum(void* arg)
{
	int *index = arg;
	int sum = index[0]+index[1]+index[2]+index[3]+index[4];
	sleep(1);
	printf("Sum: %d\n", sum);
}

void* avg(void* arg)
{
	int *index = arg;
	int sum = index[0]+index[1]+index[2]+index[3]+index[4];
	int avg = sum/5;
	sleep(1);
	printf("Avg: %d\n", avg);
}

void* cou(void* arg)
{
    int *index = arg;
    int x = 0;
    int sentinel = -1;

    while (index[x] != NULL)
    {
        x++;
    }

    sleep(1);
    printf("Count: %d\n", x);
}

int main()
{
	pthread_t thread1, thread2, thread3;
	pthread_create(&thread1, NULL, sum, (void*)arr);
	pthread_create(&thread2, NULL, avg, (void*)arr);
	pthread_create(&thread3, NULL, cou, (void*)arr);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	return 0;
}
