#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 6

int queue[MAXSIZE];

int front = -1;
int rear = -1;

void enque(int value)
{
    if(rear == MAXSIZE - 1)
    {
        printf("Queue is full.");
    }
    else if (front == -1 && rear == -1)
    {
        front ++;
        rear ++;
        queue[rear] = value;
        printf("%d enqued.",queue[rear]);
    }
    else{
            rear++;
            queue[rear] = value;
            printf("%d enqued.",queue[rear]);
    }
}

void deque()
{
    if(front == -1)
    {
        printf("Queue is already empty.");
    }
    else if (front == rear)
    {
        printf("%d dequeued",queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("%d dequeued",queue[front]);
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
        printf("Front = %d\n",queue[front]);
        printf("Rear = %d",queue[rear]);
    }
}

void display()
{
    if(front == -1 )
    {
        printf("Queue is empty.");
    }
    else
    {
        printf("FRONT -> ");
        for(int i = front; i<= rear; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("<- REAR");
    }
}

int main()
{
    int s,value;
    while(1)
    {
        printf("\nMENU : 1-Enque\n2-Deque\n3-Peek\n4-Display\n5-Exit");
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