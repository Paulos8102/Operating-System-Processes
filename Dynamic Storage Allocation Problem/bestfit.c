#include<stdio.h>

void main()
{
    int fragment[20],b[20],p[20],i,j,nb,np,temp,lowest=9999; static int barray[20],parray[20];
    printf("\n\t\t\tMemory Management Scheme - Best Fit"); 
    printf("\nEnter the number of blocks:"); 
    scanf("%d",&nb);
    printf("Enter the number of processes:"); 
    scanf("%d",&np);
    printf("\nEnter the size of the blocks:-\n"); 
    for(i=1;i<=nb;i++)
        {
            printf("Block no.%d:",i);
            scanf("%d",&b[i]);
        }
    printf("\nEnter the size of the processes :-\n"); 
    
    for(i=1;i<=np;i++)
        {
            printf("Process no.%d:",i);
            scanf("%d",&p[i]);
        }
