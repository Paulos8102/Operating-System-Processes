#include<stdio.h>
 
int main()
{
    int n,temp,temp1,temp2,b[20],b1[20],a[20],p[20],i,j; 
    float att=0,awt=0;
    int m,count=0,end,time,tat[n],wt[n]; 
    int x[n+1];

    printf("\nEnter number of process: ");
    scanf("%d",&n);

    printf("\nEnter Burst & Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:\n\tBurst  : ",i+1);
        scanf("%d",&b[i]);
        printf("\tArrival: ");
        scanf("%d",&a[i]);
    }

    for(i=0; i<n; i++) 
        x[i]=b[i]; 
    
    x[n+1]=0; 
    
    for(time=0; count!=n; time++) 
    { 
        m=n+1; 

        for(i=0; i<n; i++) 
            if(a[i]<=time && x[i]>x[m] && x[i]<9999) 
                m=i; 
        
        x[m]--; 
        
        if(x[m]==0) 
        { 
            count++; 
            end=time+1; 
            wt[m]=end-a[m]-b[m]; 
            tat[m]=end-a[m]; 
        } 
    } 
     
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time");
    printf("\n-------\t----------\t------------\t------------\t---------------\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]\t  %d\t\t      %d\t\t    %d\t\t\t%d\n",i+1,b[i],a[i],wt[i],tat[i]);
        awt=awt+wt[i]; 
        att=att+tat[i]; 
    }

    awt=awt/n; 
    att=att/n; 

    printf("\nAverage Waiting Time   : %f",awt);
    printf("\nAverage Turnaround Time: %f\n",att);
}