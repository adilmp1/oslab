#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// 82 170 43 140 24 16 190
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int bubbleSort(int a[], int n,int head)
{
    int headIndex=0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                if(a[j]==head)
                {
                    headIndex=j+1;
                }
                else if(a[j+1]==head)
                {
                    headIndex=j;
                }
                swap(a + j, a + j + 1);
            }
        }
    }
    return headIndex;
}

int CSCAN(int req[],int n, int head,int t)
{
    req[n]=0;   
    req[n+1]=head;
    req[n+2]=t-1;

    int headIndex = bubbleSort(req,n+3,head);

    for(int i=headIndex;i<n+3;i++)
    {
        printf("%d -> ",req[i]);
    }
    for(int i=headIndex-1;i>0;i--)
    {
        printf("%d",req[i]);
        if(i!=1)
        {
            printf(" -> ",req[i]);
        }
    }
    int seekTime = 2*t-2-head-req[1];
    return seekTime;
}
void main()
{
    // int n, i, head, t;
    // printf("Enter no. of requests : ");
    // scanf("%d", &n);
    // printf("\nEnter the sequence of requests: ");
    // int req[n+3];
    // for (i = 0; i < n; i++)
    // {
    //     scanf("%d", req + i);
    // }

    // printf("Enter position of head: ");
    // scanf("%d", &head);

    // printf("Enter no. of tracks: ");
    // scanf("%d", &t);


    int n=7;
    int req[]={82, 170, 43, 140, 24, 16, 190};
    int head=50;
    int t=200;

    int totalseek = CSCAN(req, n, head, t);

    printf("\n TOTAL SEEKTIME = %d \n", totalseek);
}