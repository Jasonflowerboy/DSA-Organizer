#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5
int cqueue[MAXSIZE];
int front = -1;
int rear = -1;


void enque(int value)
{
    if((front == 0 && rear == MAXSIZE-1) || (front == rear+1) )
    {
        printf("Queue is Full.");
    }
    else
    {
        if(front == -1 && rear == -1)
        {
            front++;
            rear++;
            cqueue[rear] = value;
        }
        else if(rear == MAXSIZE-1 && front !=0){
            rear = 0;
            cqueue[rear] = value;
        }
        else
        {
            rear++;
            cqueue[rear] = value;
        }
        printf("%d enqued.",cqueue[rear]);
    }
}


void deque()
{
    if(front == -1 )
    {
        printf("Queue is already empty");
    }
    else if (front == rear)
    {
        printf("%d dequeued",cqueue[front]);
        front = -1;
        rear = -1;
    }
    else if(front == MAXSIZE-1)
    {
        printf("%d dequeued.",cqueue[front]);
        front = 0;
    }
    else
    {
        printf("%d dequeued",cqueue[front]);
        front++;
    }
}


void peek()
{
    if(front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("FRONT = %d\n",cqueue[front]);
        printf("REAR = %d",cqueue[rear]);
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty.");
    }
    else if(front<rear || front == rear)
    {
        printf("FRONT -> ");
        for(int i = front; i<=rear; i++)
        {
            printf("%d ",cqueue[i]);
        }
        printf("<- REAR");
    }
    else if (rear<front)
    {
        printf("FRONT -> ");
        for(int i=front; i<= MAXSIZE-1; i++)
        {
            printf("%d ",cqueue[i]);
        }
        for(int i=0; i<= rear; i++)
        {
            printf("%d ",cqueue[i]);
        }
        printf("<- REAR");
    }
}

int main()
{
    int s,value;
    while(1)
    {
        printf("\nMENU:1-Enque\n2-Deque\n3-Peek\n4-Display\n5-Exit : ");
        scanf("%d",&s);
        switch(s)
        {
            case 1 : printf("Enter the value to enque : ");
                     scanf("%d",&value);
                     enque(value);
                     break;

            case 2 : deque();
                     break;

            case 3 : peek();
                     break;

            case 4 : display();
                     break;

            case 5 : exit(0);
        }
    }
    return 0;
}