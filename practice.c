#include <stdio.h>
typedef struct{
    int at,bt,wt,tat,ct,status;
}process;

void sortWithBurstTime(process a[],int n)
{
    process temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j].bt>a[j+1].bt)
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int main()
{
    int n,i;    
    int totalTAT=0,totalWT=0,completed=0,currentTime=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process a[n];
    printf("Enter the arrival time and burst time\n");
    int sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i].at);
        scanf("%d",&a[i].bt);
        sum+=a[i].bt;
        a[i].status=0;
    }
    while(completed<n)
    {
        int sJob=-1;
        int sBt = 99999;
        for(int i=0;i<n;i++)
        {
            if(a[i].status==0 && a[i].bt<sBt && a[i].at<=currentTime)
            {
                sJob = i;
                sBt = a[i].bt;
            }
        }
        if(sJob==-1)
        {
            currentTime++;
        }
        else
        {
            a[sJob].ct=currentTime+a[sJob].bt;
            currentTime = a[sJob].ct;
            a[sJob].tat = a[sJob].ct-a[sJob].at;
            a[sJob].wt = a[sJob].tat-a[sJob].bt;
            totalTAT+=a[sJob].tat;
            totalWT+=a[sJob].wt;
            completed++;
                a[sJob].status=1;
        }
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
