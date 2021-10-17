#include<stdio.h>
 
int main()
{
    int bt[20],a[20],pr[20],wt[20],tat[20],i,j,total=0,pos,temp,n; 
    float avg_wt,avg_tat; 

    printf("\nEnter number of process: ");
    scanf("%d",&n);

    printf("\nEnter Burst Time & Priority:\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:\n\tBurst   : ",i+1);
        scanf("%d",&bt[i]);
        printf("\tPriority: ");
        scanf("%d",&pr[i]);
    }

    for(i=0;i<n;i++) 
    { 
        pr[i]=i; 
        wt[i]=0; 
        tat[i]=0; 
    } 
    
    for(i=0;i<n;i++) 
    { 
        pos=i; 

        for(j=i+1;j<n;j++) 
            if(pr[j]<pr[pos]) 
                pos=j; 
    
    
        temp=pr[i]; 
        pr[i]=pr[pos]; 
        pr[pos]=temp; 
        
        temp=bt[i]; 
        bt[i]=bt[pos]; 
        bt[pos]=temp; 
        
        temp=pr[i]; 
        pr[i]=pr[pos]; 
        pr[pos]=temp; 
    } 
    
    wt[0]=0; 
    for(i=1;i<n;i++) 
    { 
    wt[i]=0; 
    for(j=0;j<i;j++) 
    wt[i]+=bt[j]; 
    
    total+=wt[i]; 
    } 
    
    avg_wt=total/n; 
    total=0; 

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    printf("\n-------\t----------\t------------\t---------------\n");
    
    for(i=0 ; i<n ; i++) 
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
        
    } 
    
    avg_tat=total/n;
    
    printf("\n\nAverage Waiting Time   : %f sec",avg_wt);
    printf("\nAverage Turnaround Time: %f sec\n",avg_tat);
}