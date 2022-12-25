#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/*
This program provides a possible solution using mutex and semaphore.
use 5 Fsrmers and 5 ShopOwner to demonstrate the solution.
*/

#define MaxCrops 5
#define warehouseSize 5

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize]={'R','W','P','S','M'};//indicatig room for different crops
char warehouse[warehouseSize]={'N','N','N','N','N'};//initially all the room is empty
pthread_mutex_t mutex;

void *Farmer(void *far)
{
    /*
  1.Farmer harvest crops and put them in perticular room. For example, room 0 for Rice(R).
  2.use mutex and semaphore for critical section.
  3.print which farmer is keeping which crops in which room inside the critical section.
  4.print the whole warehouse buffer outside of the critical section
  */
    int item;
    int i;
    int *farmer = (int *)far;
    for(i=0;i<MaxCrops;i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        item = *farmer;
        warehouse[in] = crops[item];
        printf("Farmer %d: insert %c at %d\n",*farmer,crops[item],in);
        in = (in+1)%warehouseSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    printf("Farmer%d: ",*farmer);
    for(i=0;i<warehouseSize;i++)
    {
        printf("%c",warehouse[i]);
    }
    printf("\n");
}
void *ShopOwner(void *sho) {
    int item;
    int i;
    int *shopowner = (int *)sho;
    for(i=0;i<MaxCrops;i++)
    {
        /*
   1.Shop owner take crops and make that perticular room empty.
   2.use mutex and semaphore for critical section.
   3.print which shop owner is taking which crops from which room inside the critical section.
   4.print the whole warehouse buffer outside of the critical section
   */
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = *shopowner;
        warehouse[out] = 'N';
        printf("Shop owner %d: Remove crops %c from %d\n",*shopowner,crops[item],out);
        out = (out+1)%warehouseSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    printf("ShopOwner%d: ",*shopowner);
    for(i=0;i<warehouseSize;i++)
    {
        printf("%c",warehouse[i]);
    }
    printf("\n");
}
int main() {
    /*intializing thread,mutex,semaphore
   */
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,warehouseSize);//when the wearehouse is full thread will wait
    sem_init(&full,0,0);//when the wearehouse is empty thread will wait

    int a[5] = {1,2,3,4,5}; //Just used for numbering the Farmer and ShopOwner
    /*creat 5 thread for Farmer 5 thread for ShopOwner
    -------------------------------------------------
    -------------------------------------------------
    */
    for(int i=0;i<5;i++)
    {
        pthread_create(&Far[i], NULL, Farmer, &a[i]);
    }
    for(int i=0;i<5;i++)
    {
        pthread_create(&Sho[i], NULL, ShopOwner, &a[i]);
    }
    for(int i=0;i<5;i++) {
        pthread_join(Far[i], NULL);
    }

    for(int i=0;i<5;i++)
    {
        pthread_join(Sho[i], NULL);
    }

    //  Closing/distroying mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;

}
