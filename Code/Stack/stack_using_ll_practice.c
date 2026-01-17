#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *TOP = NULL;


void push(int value)
{
    struct stack *newNode;
    newNode = (struct stack*)malloc(sizeof(struct stack));
    if(newNode == NULL)
    {
        printf("Stack Full.");
        return;
    }
    newNode->data = value;
    newNode->next = TOP;
    TOP = newNode;
    printf("%d pushed.",TOP->data);
}

void pop()
{
    if(TOP == NULL)
    {
        printf("Stack is already empty.");
    }
    else
    {
        struct stack *temp;
        temp = TOP;
        TOP = TOP->next;
        printf("%d popped.",temp->data);
        free(temp);
    }
}


void peek()
{
    if(TOP == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("TOP = %d",TOP->data);
    }
}


void display()
{
    if(TOP == NULL)
    {
        printf("Stack is empty.");
    }
    else
    {
        struct stack *temp;
        temp = TOP;
        printf("TOP -> ");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int value,s;
    while(1)
    {
        printf("\nMENU:1-Push\n2-Pop\n3-Peek\n4-Display\n5-Exit : ");
        scanf("%d",&s);
        switch(s)
        {
            case 1 : printf("Enter the value to push : ");
                    scanf("%d",&value);
                    push(value);
                    break;

            case 2 : pop();
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