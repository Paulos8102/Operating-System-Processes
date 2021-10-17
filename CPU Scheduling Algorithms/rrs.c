#include<stdio.h>
 
int main()
{
    int i,j,q,c,n,bt[20],at[20],temp[20],total,tat=0,wt=0,p[20]; 
    float att=0,awt=0; 

    printf("\nEnter number of process: ");
    scanf("%d",&n);

    printf("\nEnter Burst & Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:\n\tBurst  : ",i+1);
        scanf("%d",&bt[i]);
        printf("\tArrival: ");
        scanf("%d",&at[i]);
    }
    
    printf("\nEnter the time quantum: "); 
    scanf("%d",&q); 

    for(i=0;i<n;i++) 
    { 
        p[i]=i+1; 
        temp[i]=bt[i]; 
    } 

    int x=n; 

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time");
    printf("\n-------\t----------\t------------\t------------\t---------------\n");
    
    for(total=0,i=0; x!=0;) 
    { 
        if(temp[i]<=q && temp[i]>0) 
        { 
            total=total+temp[i]; 
            temp[i]=0; 
            c=1; 
        }
        
        else if(temp[i]>0) 
        { 
            temp[i]=temp[i]-q; 
            total=total+q; 
        } 

        if(temp[i]==0 && c==1) 
        { 
            x--; 
            printf("\nP[%d]\t%d\t\t%d\t\t%d\t\t\t%d",p[i],bt[i],at[i],total-at[i]-bt[i],total-at[i]); 
            wt=wt+total-at[i]-bt[i]; 
            tat=tat+total-at[i]; 
            c=0; 
        } 

        if(i == n-1) 
            i=0; 
        else if(at[i+1] <= total) 
            i++; 
        else 
            i=0; 
    } 
    awt=wt/n; 
    att=tat/n; 
    
    printf("\n\nAverage Waiting Time   : %f sec",awt);
    printf("\nAverage Turnaround Time: %f sec\n",att);
 }