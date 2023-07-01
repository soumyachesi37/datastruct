#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 10

struct queue
{
    int data[MAX_QUEUE];
    int front, rear;
};

void enQueue(struct queue*, int);
int deQueue(struct queue*);
int peekQueue(struct queue*);
int isQueueEmpty(struct queue*);
void displayQueue(struct queue*);

int main()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;
    int choice=1,x; 
    printf("/Queue Implementation using Array/\n");
    while(choice!=0)
    {
        printf("\n1-Enqueue\n2-Dequeue\n3-Peek\n4-CheckIfEmpty\n5-Display\n0-Exit\n");
        printf("Enter - ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                break;
            case 1:
                scanf("%d",&x);
                enQueue(&q,x);
                break;
            case 2: 
                deQueue(&q);    
                break;
            case 3:
                peekQueue(&q);
                break;
            case 4:
                if(isQueueEmpty(&q))
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 5: 
                displayQueue(&q);
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }   
}

void enQueue(struct queue* q, int x)
{
    //printf("Inside enQueue\n");
    if(isQueueEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
        q->data[q->rear] = x;
        //printf("%d pushed to queue\n",q->data[q->rear]);
        return;
    }
    if(q->front == 0 && q->rear < MAX_QUEUE-1)
    {
        q->rear++;
        q->data[q->rear] = x;
        //printf("%d pushed to queue\n",q->data[q->rear]);
        return;
    }
    if(q->rear == MAX_QUEUE-1)
    {
        printf("Queue is full\n");
    }
    return;
}
int deQueue(struct queue *q)
{
    //printf("Inside deQueue\n");
    int x;
    if(isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return 0;
    }
    if(q->rear == 0)
    {
        x = q->data[0];
        q->front = -1;
        q->rear = -1;
        //printf("%d is dequeued\n",x);
        return x;
    }
    x = q->data[q->front];
    for(int i = q->front; i < q->rear; i++)
        q->data[i] = q->data[i+1];
    q->rear--;
    //printf("%d is dequeued\n",x);
    return x;
}
int peekQueue(struct queue *q)
{
    printf("Inside peekQueue\n");
    return 0;
}
int isQueueEmpty(struct queue *q)
{
    //printf("Inside isQueueEmpty\n");
    return (q->front == -1);
}
void displayQueue(struct queue *q)
{
    //printf("Inside displayQueue\n");
    if(isQueueEmpty(q))
    {
        printf("Queue Empty\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++)
        printf("%d ",q->data[i]);
    printf("\n");
    return;
}