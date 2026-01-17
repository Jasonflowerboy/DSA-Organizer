#include<stdio.h>
#include<stdlib.h>
/*DEQUE behaves as a CQ so it wraps around. Front adds to the Left so behind, and after deleteing, moves to the right so forward.
Rear adds to the Right so forward and, and after deleting, moves to the left so behind*/
#define MAXSIZE 5

int deque[MAXSIZE];
int front = -1;
int rear = -1;

void insert_rear(int value)
{
    if((front == 0 && rear == MAXSIZE-1) || (front == rear+1))
    {
        printf("Queue is full.");
    }
    else if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        deque[rear] = value;
        printf("%d inserted.",deque[rear]);
    }    
    else if(rear==MAXSIZE-1 && front != 0)
    {
        rear = 0;
        deque[rear] = value;
        printf("%d inserted",deque[rear]);
    }
    else
    {
        rear++;
        deque[rear] = value;
        printf("%d inserted.",deque[rear]);
    }
    
}


void delete_rear()
{
    if(front == -1 && rear == -1)
    {
        printf("The queue is already empty.");
    }
    else if(front == rear)
    {
        printf("%d deleted",deque[rear]);
        front = -1;
        rear= -1;
    }
    else if (rear == 0)
    {
        printf("%d deleted",deque[rear]);
        rear = MAXSIZE-1;
    }
    else{
        printf("%d deleted",deque[rear]);
        rear--;
    }
}


void insert_front(int value)
{
    if((front == 0 && rear ==MAXSIZE-1) || (front == rear+1))
    {
        printf("Queue is full");
    }
    else if(front == -1 && rear == -1)
    {
        front ++;
        rear ++;
        deque[front] = value;
        printf("%d inserted",deque[front]);
    }
    else if(front == 0 && rear != MAXSIZE-1)
    {
        front = MAXSIZE-1;
        deque[front] = value;
        printf("%d inserted",deque[front]);
    }
    else
    {
        front--;
        deque[front] = value;
        printf("%d inserted",deque[front]);
    }
}



void delete_front()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is already empty");
    }
    else if(front == rear)
    {
        printf("%d deleted",deque[front]);
        front = -1;
        rear = -1;
    }
    else if(front == MAXSIZE-1)
    {
        printf("%d deleted",deque[front]);
        front = 0;
    }
    else
    {
        printf("%d deleted", deque[front]);
        front ++;
    }
    
}


void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if (front<rear || front == rear)
    {
        printf("FRONT -> ");
        for(int i=front; i<=rear; i++)
        {
            printf("%d ",deque[i]);
        }
        printf("<- REAR");
    }
    else if(rear<front)
    {
        printf("FRONT -> ");
        for(int i=front; i<=MAXSIZE-1; i++)
        {
            printf("%d ",deque[i]);
        }
        for(int i=0; i<=rear; i++)
        {
            printf("%d ",deque[i]);
        }
        printf("<-REAR");
    }
}
int main()
{
    int s,value;
    while(1)
    {
        printf("\nMENU:1-Insert Rear\n2-Delete Rear\n3-Insert Front\n4-Delete Front\n5-Display\n6-Exit : ");
        scanf("%d",&s);
        switch(s)
        {
            case 1 : printf("Enter the value to insert ");
                scanf("%d",&value);
                insert_rear(value);
                break;

            case 2 : delete_rear();
                     break;

            case 3 : printf("Enter the value to insert : ");
                scanf("%d",&value); 
            insert_front(value);
            break;

            case 4 : delete_front();
                   break;

            case 5 : display();
                     break;

            case 6 : exit(0);
        }
    }
return 0;
}