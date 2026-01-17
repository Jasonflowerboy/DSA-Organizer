#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5
int TOP = -1;
int stack[MAXSIZE];

void push(int value)
{
    if(TOP==MAXSIZE-1)
    {
        printf("STACK IS FULL.");
    }
    else
    {
        TOP++;
        stack[TOP] = value;
        printf("%d pushed.",stack[TOP]);
    }
}

void pop()
{
    if(TOP == -1)
    {
        printf("Stack is already empty.");
    }
    else
    {
        printf("%d popped.",stack[TOP]);
        TOP --; 
    }
}

void peek()
{
    if(TOP == -1)
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("TOP = %d",stack[TOP]);
    }
}


void display()
{
    if(TOP == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("TOP -> ");
        for(int i = TOP;i>=0; i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
int main()
{
    int value,s;
    while(1)
    {
        printf("\nMENU:1-Push\n2-Pop\n3-Peek\n4-Display\n5-Exit : \n");
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