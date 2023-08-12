#include<stdio.h>
#include<stdlib.h>
int fcfs(int req[],int n,int head)
{
    int seek=0;
    for(int i=0;i<n;i++)
    {
        seek+=abs(head-req[i]);
        head=req[i];
    }
    return seek;
}
void main(){
    int n,i,head;
    printf("Enter no. of requests : ");
    scanf("%d",&n);
    int req[n];
    printf("Enter the sequence of requests: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",req+i);
    }
    printf("Enter position of head: ");
    scanf("%d",&head);

    int seek = fcfs(req,n,head);

    printf("seek timee = %d \n",seek);
}