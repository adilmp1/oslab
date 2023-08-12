#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int findSSTRequest(int req[],int head,int n)
{
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(abs(head-req[i])<abs(head-req[index]))
        {
            index=i;
        }
    }
    return index;
}
void display(int sequence[],int ind,int head)
{
    printf("%d -> ",head);
    for(int i=0;i<ind;i++)
    {
        printf("%d",sequence[i]);
        if(i!=ind-1)
        {
            printf(" -> ");
        }
    }
}
int sstf(int req[],int n, int head)
{
    int seekTime=0,sequence[100];
    int first=head;
    int ind=0;
    int sstfIndex = findSSTRequest(req,head,n);
    while(req[sstfIndex]!=INT_MAX)
    {
        seekTime+=abs(head-req[sstfIndex]);
        head = req[sstfIndex];
        sequence[ind++]=head;
        req[sstfIndex]=INT_MAX;
        sstfIndex = findSSTRequest(req,head,n);
    }
    display(sequence,ind,first);
    return seekTime;
}
void main(){
    // int n,i,head;
    // printf("Enter no. of requests : ");
    // scanf("%d",&n);
    // int req[n];
    // printf("Enter the sequence of requests: ");
    // for(i=0;i<n;i++)
    // {
    //     scanf("%d",req+i);
    // }
    // printf("Enter position of head: ");
    // scanf("%d",&head);

    // int seek = sstf(req,n,head);

    int n=7;
    int req[]={82, 170, 43, 140, 24, 16, 190};
    int head=50;
    int seek = sstf(req,n,head);

    printf("\nseek time = %d \n",seek);
}