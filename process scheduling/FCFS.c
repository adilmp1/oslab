#include <stdio.h>
typedef struct{
    int at,bt,wt,tat,ct;
}process;
int main()
{
    int n,i;    
    int totalTAT=0,totalWT=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process a[n];
    printf("Enter the arrival time and burst time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i].at);
        scanf("%d",&a[i].bt);
    }
    printf("Enter the burst times of n processes: ");
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum+=a[i].bt;
        a[i].ct=sum;
        a[i].tat = a[i].ct-a[i].at;
        a[i].wt = a[i].tat-a[i].bt;
        totalTAT+=a[i].tat;
        totalWT+=a[i].wt;
    }
    float avgTAT = (float)totalTAT/n;
    float avgWT = (float)totalWT/n;
    printf("\nPNo\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
    }
    printf("\n");
    printf("Average Waiting time = %f\n",avgWT);
    printf("Average Turn Around time = %f\n",avgTAT);

}
