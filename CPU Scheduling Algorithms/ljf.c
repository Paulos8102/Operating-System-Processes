//Longest Job First

#include<stdio.h>
int main()
{
 int n,temp,temp1,temp2,b[20],b1[20],t[20],w[20],p[20],i,j;
 float att=0,awt=0;
  
 printf("\nEnter number of process: ");
 scanf("%d",&n);
  
 printf("\nEnter Burst Time:\n");
  
 for(i=0;i<n;i++)
 {
   printf("P[%d]: ",i+1);
   scanf("%d",&b[i]);
 }
 
 for(i=0;i<n;i++)
 {
   p[i]=i+1;
   b1[i]=b[i];
 }
  
 for(i=0;i<n-1;i++)
 {
   for(j=1;j<n;j++)
   {
     if(b1[i]<b1[j])
     {
       temp=b1[i];
       b1[i]=b1[j];
       b1[j]=temp;

       temp1=p[i];
       p[i]=p[j];
       p[j]=temp1;
     }
   }
 }
  
 w[0]=0;
  
 for(i=0;i<n;i++)
  w[i+1]=w[i]+b1[i];
  
 for(i=0;i<n;i++)
 {
   t[i]=w[i]+b1[i];
   awt=awt+w[i];
   att=att+t[i];
 }
 
 awt=awt/n;
 att=att/n;
  
 printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
 printf("\n-------\t----------\t------------\t---------------\n");
  
 for(i=0;i<n;i++)
  printf("P[%d]\t %d\t\t %d\t\t\t%d\n",p[i],b1[i],w[i],t[i]);
  
 printf("\nAverage Waiting Time : %f",awt);
 printf("\nAverage Turnaround Time: %f\n",att);
}
