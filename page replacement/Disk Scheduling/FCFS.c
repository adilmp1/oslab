#include<stdio.h>
#include<stdlib.h>
//82 170 43 140 24 16 190
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
    for(i=0;i<n;i++){
        scanf("%d",req+i);
    }
    printf("Enter position of head: ");
    scanf("%d",&head);

    int totalseek = fcfs(req,n,head);

    printf("\n TOTAL SEEKTIME = %d \n",totalseek);
}