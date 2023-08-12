#include <stdio.h>
int noofp;
int noofr;
void display(int a[][noofr])
{
    for(int i=0;i<noofp;i++)
    {
        printf("\n");
        for(int j=0;j<noofr;j++)
        {
            printf("%d\t",a[i][j]);
        }
    }
    printf("\n\n");
}

void findNeed(int allocation[][noofr],int max[][noofr],int need[][noofr])
{
    for(int i=0;i<noofp;i++)
    {
        for(int j=0;j<noofr;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
}

int isSafe(int allocation[][noofr],int max[][noofr],int need[][noofr],int available[noofr])
{
    int finish[noofp];
    for(int i=0;i<noofp;i++)
    {
        finish[i]=0;
    }
    int work[noofr];
    for(int i=0;i<noofr;i++)
    {
        work[i]=available[i];
    }
    int completed=0;
    while(completed<noofp)
    {
        int finishIsfalse=0;
        for(int i=0;i<noofp;i++)
        {
            if(!finish[i])
            {
                int flag=1;
                for(int j=0;j<noofr;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        flag=0;
                    }
                }
                if(flag)
                {
                    for(int j=0;j<noofr;j++)
                    {
                        work[j]+=allocation[i][j];
                    }
                    printf("P%d -> ",i);
                    finish[i]=1;
                    completed++;
                    finishIsfalse=1;
                }
            }
        }
        if(finishIsfalse==0)
        {
            break;
        }
    }

    if(completed<noofp)
        return 0;
    return 1;
}
int main()
{
    noofp=5,noofr=3;
    // printf("Enter the no of processes: ");
    // scanf("%d",&n);
    // printf("Enter the no of resources: ");
    // scanf("%d",&m);

    // int allocation[n][m];
    // int max[n][m];
    // int available[m];

    int need[noofp][noofr];
    int allocation[5][3] = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} };
    int max[5][3] = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} };
    int available[3] = {3,3,2};


    // printf("Enter the allocation matrix\n");
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         scanf("%d",&allocation[i][j]);
    //     }
    // }
    // printf("Enter the maximum demand matrix\n");
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         scanf("%d",&max[i][j]);
    //     }
    // }

    // printf("Enter the available resources: ");
    // for(int i=0;i<m;i++)
    // {
    //     scanf("%d",&available[m]);
    // }
    // display(allocation);
    // display(max);
    findNeed(allocation,max,need);
    if(isSafe(allocation,max,need,available))
    {
        printf("\nSystem is in safe state\n");
    }
    else
    {
        printf("\nSystem is not in safe state\n");
    }
    // display(need);

}
