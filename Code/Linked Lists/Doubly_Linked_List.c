#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *create(struct node *head, int num)
{
    struct node *newNode, *tail = head;
    int value;
    for(int i=1;i<=num;i++)
    {
         newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory full. Exiting");
        exit(0);
    }
    printf("Enter the value for node %d ",i);
    scanf("%d",&value);
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = tail = newNode;
        newNode->prev = NULL;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Node %d Inserted",i);
    }
   return head;
}


struct node *insert_beg(struct node *head)
{
    int value;
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory Full. Exiting..");
        exit(0);
    }

    printf("Enter the value to insert : ");
    scanf("%d",&value);
    newNode->data = value;
    newNode->prev = NULL;
    if(head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }

    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node Inserted");
    return head;
}

struct node *insert_end(struct node *head)
{
    int value;
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory Full. Exiting..");
        exit(0);
    }
    printf("Enter the value to insert : ");
    scanf("%d",&value);
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
         struct node *temp;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    }
   printf("Node Inserted.");
   return head;
}


struct node *delete_beg(struct node *head)
{
    if(head == NULL)
    {
        printf("The LinkedList is already empty.");
    }
    else if(head->next == NULL)
    {
        printf("Node deleted");
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        printf("Node deleted");
        free(temp);
        head->prev = NULL;
    }
    return head;
}

struct node *delete_end(struct node *head)
{
    if (head == NULL)
    {
        printf("The LinkedList is already empty");
    }
    else if(head->next == NULL)
    {
        printf("Node deleted");
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp;
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("Node deleted");
        temp->prev->next = NULL; //Temp's prev means 2nd last node, go there and its next make it NULL.
        free(temp);
    }
    return head;
}


void display(struct node *head)
{
    if(head == NULL)
    {
        printf("The LinkedList is empty");
    }
    else
    {
        struct node *temp = head;
        printf(" NULL ");
        while(temp != NULL)
        {
            printf("<- %d ->",temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}