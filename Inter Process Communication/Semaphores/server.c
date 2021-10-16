#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/errno.h>
#include <sys/types.h>

#define SIZE 3 /* size of the shared buffer */
#define SHMPERM 0666 /* shared memory permissions */

int segid; /* ID for shared memory buffer */
sem_t *empty;
sem_t *full;
sem_t *mutex;
char *buff;

int i= 0, N=5;

int main()
{
 srand(time(0));
 segid = shmget(100, SIZE, IPC_CREAT|0666);
 buff = shmat(segid, (char *)0, 0);
 int empty_id=shmget(101,sizeof(sem_t),IPC_CREAT|0666);
 empty = shmat(empty_id,(char *)0,0);
 sem_init(empty,1,SIZE);
 int full_id=shmget(102,sizeof(sem_t),IPC_CREAT|0666);
 full = shmat(full_id,(char *)0,0);
 sem_init(full,1,0);
 int mutex_id=shmget(103,sizeof(sem_t),IPC_CREAT|0666);
 mutex = shmat(mutex_id,(char *)0,0);
 sem_init(mutex,1,1);
 sleep(3);
 while(1)
 {
   if(!N)
   {
     break;
   }
   
   printf("Server trying to acquire semaphore empty\n");
   sem_wait(empty);
   
   printf("Semaphore empty acquired by server\n");
   printf("Server trying to acquire semaphore mutex\n");
   sem_wait(mutex);
   
   printf("Semaphore mutex acquired by server\n");
   int val = rand()%10;
   
   printf("Writing %c\n",(char)(val+48));
   buff[i] = (char)(val+48);
   
   N--; 
   i++;
   
   sem_post(full);
   printf("Server released semaphore full\n");
   
   sem_post(mutex);
   printf("Server released semaphore mutex\n\n");
   
   sleep(1);
 }
 shmdt(buff);
 shmdt(empty);
 shmdt(full);
 shmdt(mutex);
  
 shmctl(segid, IPC_RMID, NULL);
 semctl( empty_id, 0, IPC_RMID, NULL);
 semctl( full_id, 0, IPC_RMID, NULL);
 semctl( mutex_id, 0, IPC_RMID, NULL);
  
 sem_destroy(empty);
 sem_destroy(full);
 sem_destroy(mutex);
}
