#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;


void enque(int value)
{
    struct queue *newNode;
    newNode = (struct queue*)malloc(sizeof(struct queue));
    if(newNode == NULL)
    {
        printf("Memory overflow. Free some space");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if(front == NULL && rear == NULL)
    {   
        front = newNode;
        rear = newNode;
         printf("%d inserted.",rear->data);
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
         printf("%d inserted.",rear->data);
    }
}

void deque()
{
    if(front == NULL)
    {
        printf("The queue is already empty.");
    }
    else if (front == rear)
    {
        struct queue* temp = front;
        printf("%d dequeued",front->data);
        free(temp);
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct queue *temp;
        temp = front;
        front = front->next;
        printf("%d dequeued",temp->data);
        free(temp);
    }
}


void peek()
{
    if(front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("FRONT = %d\n",front->data);
        printf("REAR = %d",rear->data);
    }
}


void display()
{
    if(front == NULL)
    {
        printf("Queue is empty");
    }
    else 
    {
        struct queue *temp;
        temp = front;
        printf("FRONT -> ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
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