#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int front = -1, rear = -1;
int queue[MAX];
void displayQueue()
{
    for(int i=front;i<rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int position(int item)
{
    for (int i = front; i < rear; i++)
    {
        if (queue[i] == item)
        {
            return i;
        }
    }
}
void enqueue(int item)
{
    
    if (front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear++] = item;
    }
    else
    {
        int flag=1;
        for(int i=front;i<rear;i++)
        {
            if(item==queue[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            queue[rear++] = item;
        }
    }
}
int dequeue()
{
    return queue[front++];
}
int top()
{
    return queue[front];
}
void dequeueItem(int item)
{
    for(int i=front;i<=rear;i++)
    {
        if(queue[i]==item)
        {
            for(int j=i;j>=front;j--)
            {
                swap(queue+j,queue+j-1);
            }
        }
    }
    dequeue();
}
void display(int frames[],int f,int page)
{
    printf("%d\t",page);
    for(int i=0;i<f && frames[i]!=-1;i++)
    {
        printf("%d ",frames[i]);
    }
    printf("\n");
}
void optimal(int a[],int p,int frames[],int f)
{
    int completed=0;
    while(completed<p)
    {
        enqueue(a[completed]);
        int done=0;
        for(int i=0;i<f;i++)
        {
            if(frames[i]==a[completed])
            {
                display(frames,f,a[completed]);
                if(a[completed]==1)
                {
                    printf("hi\n");
                }
                completed++;
                done=1;
                break;
            }
        }
        if(!done)
        {
            for(int i=0;i<f;i++)
            {
                if(frames[i]==-1)
                {
                    frames[i]=a[completed];
                    display(frames,f,a[completed]);
                    completed++;
                    done=1;
                    break;
                }
            }
        }
        if(!done)
        {
            int finish[f];
            int count=0;
            for(int i=0;i<f;i++)
            {
                finish[i]=0;
            }
            for(int i=completed;i<p;i++)
            {
                if(count==(f-1))
                {
                    for(int j=0;j<f;j++)
                    {
                        if(finish[j]==0)
                        {
                            // printf("%d\n",frames[j]);
                            // printf("-1\t%d\n",frames[j]);
                            dequeueItem(frames[j]);
                            frames[j]=a[completed];
                            done=1;
                            display(frames,f,a[completed]);
                            // if(a[completed]==4)
                            // {
                            //     printf("hjkkjh ");
                            //     printf("%d ",frames[0]);
                            //     printf("%d ",frames[1]);
                            //     printf("%d ",frames[2]);
                            //     exit(0);
                            // }
                            // printf("\n");
                            completed++;
                            break;
                        }
                    }
                }
                if(!done)
                {
                    for(int j=0;j<f;j++)
                    {
                        if(frames[j]==a[i])
                        {
                            finish[j]=1;
                            count++;
                            break;
                        }
                    }
                }
                
            }
            if(!done)
            {
                int index=9999;
                for(int i=0;i<f;i++)
                {
                    if(finish[i]==0)
                    {
                        if(position(frames[i])<index)
                        {
                            index=position(frames[i]);
                        }
                    }
                }
                dequeueItem(frames[index]);
                frames[index]=a[completed];
                done=1;
                display(frames,f,a[completed]);
                completed++;
            }
        }
    }
}
int main()
{
    int a[] = {3,2,1,3,4,1,6,2,4,3,4,2,1,4,5,2,1,3,4};
    int no_of_pages=19;
    int no_of_frames=3;
    int frames[3]={-1,-1,-1};

    // enqueue(1);
    // enqueue(2);
    // enqueue(3);
    // enqueue(4);
    // enqueue(5);
    // enqueue(5);
    // enqueue(5);

    // displayQueue();
    // printf("%d ",queue[2]);
    optimal(a,no_of_pages,frames,no_of_frames);

}
