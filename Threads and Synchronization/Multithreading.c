#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

float balance=1000; 
static float least_amt=2000; 

void* deposit() 
{ 
 float d; 
 printf("\nEnter the amt to deposit:"); 
 scanf("%f",&d); 
 balance += d; 
 printf("\nDeposit Successfull\n"); 
} 

void* withdraw() 
{ 
 pthread_t tid2; 
 printf("\nEnter the amt to withdraw:"); 
 float wd; 
 scanf("%f",&wd); 
  
 rep: 
  
 if(balance-wd >= least_amt) 
 { 
   balance-=wd; 
   printf("\nWithdrawal Successfull\n"); 
 } 
 else
 { 
   printf("\nBalance Insufficient. Waiting for deposit\n"); 
   pthread_create(&tid2,NULL,deposit,NULL); 
   pthread_join(tid2,NULL); 
   goto rep; 
 } 
}

int main() 
{ 
 pthread_t tid1; 
 printf("Started main thread\n"); 
 pthread_create(&tid1,NULL,withdraw,NULL); 
 pthread_join(tid1,NULL); 
  
 return(0);
}
