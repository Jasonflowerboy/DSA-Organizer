#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *create(struct node * head, int n)
{
    int value;
    struct node *newNode;
    struct node *tail = head;
    for(int i=1; i<=n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode == NULL)
        {
            printf("Memory full. Exiting");
            exit(0);
        }

        printf("Enter the value of node %d: ",i);
        scanf("%d",&value);
        newNode ->data = value;
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        newNode->next = head;
        printf("Node %d created\n",i);
    }
    return head;
}


struct node *insert_beg(struct node *head)
{
    struct node *newNode;
    int value;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory is full. Exiting..");
        exit(0);
    }
    printf("Enter the value to insert : ");
    scanf("%d",&value);
    newNode->data = value;
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        printf("Node inserted.");
    }
    else
    {
        struct node *temp;
        temp = head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
         printf("Node inserted.");
    }
    return head;
}

struct node *insert_end(struct node *head)
{
    struct node *newNode;
    int value;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory full. Exiting..");
        exit(0);
    }
    printf("Enter the value to insert : ");
    scanf("%d",&value);
    newNode->data = value;
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct node *temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node Inserted");
    return head;
}


struct node *insert_pos(struct node *head, int pos)
{
    struct node *newNode;
    int value;
    newNode = (struct node*)malloc(sizeof (struct node));
    if(newNode == NULL)
    {
        printf("Memory full. Exiting..");
        exit(0);
    }
    printf("Enter the value to insert : ");
    scanf("%d",&value);
    newNode->data = value;
    if(pos == 1 || head == NULL)
    {
        if(head!=NULL)
        {
            struct node *temp = head;
            while(temp->next !=head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        else //head is NULL
        {
            head = newNode;
            newNode->next = head;
        }
    }
    else
    {
        struct node *temp = head;
        for(int i=1; i<pos-1 && temp->next != head; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted");
    return head;
}


struct node *delete_beg(struct node *head)
{
    if(head == NULL)
    {
        printf("The LinkedList is already empty");
    }
    else if(head->next == head)
    {
        printf("Node deleted");
        free(head);
        head = NULL;
    }
    else
    {
        struct node *tail, *temp;
        tail = head;
    while(tail->next != head)
    {
        tail = tail->next;
    }
    temp = head;
    head = head->next;
    tail->next = head;
    printf("Node deleted");
    free(temp);
    }
    return head;
}


struct node *delete_end(struct node *head)
{
    if(head == NULL)
    {
        printf("The LinkedList is already empty.");
    }
    else if(head->next == head)
    {
        printf("Node deleted");
        free(head);
        head = NULL;
    }
    else
    {
        struct node *prev, *temp;
        temp = head;
        prev = NULL;
        while(temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        printf("Node deleted");
        free(temp);
        prev->next = head;
    }
    return head;
}

struct node *delete_pos(struct node *head, int pos)
{
    if(head == NULL)
    {
        printf("The LinkedList is already empty");
    }
    else if( pos == 1 && head->next == head )
    {
        printf("Node deleted");
        free(head);
        head = NULL;
    }
    else if (pos == 1)
    {
        struct node *tail, *temp;
        tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        temp = head;
        head = head->next;
        tail->next = head;
        printf("Node deleted");
        free(temp);
    }
    else
    {
        struct node *prev = NULL, *temp = head;
        for(int i =1; i<pos && temp->next != head; i++)
        {
                prev = temp;
                temp = temp->next;
        }
        prev->next = temp->next;
        printf("Node deleted");
        free(temp);
    }
    return head;
}

void display(struct node *head)
{
    if(head == NULL)
    {
        printf("The LinkedList is empty.");
    }
    else
    {
        struct node *temp = head;
        printf("THE LINKEDLIST IS -> ");
        do{
            printf("%d -> ",temp->data);
            temp = temp->next;
        }while(temp!=head);
        printf("HEAD");
    }
}

int main()
{
    struct node *head = NULL;
    int value,pos,n,s;
    while(1)
    {
        printf("\nMENU:1-Create a list\n2-Insert_Beg\n3-Insert_End\n4-Insert_Pos\n5-Delete_Beg\n6-Delete_End\n7Delete_Pos\n8-Display\n9-Exit : ");
        scanf("%d",&s);
        switch(s)
        {
            case 1 : printf("Enter the number of nodes to create : ");
                     scanf("%d",&n);
                     head = create(head,n);
                     break;


            case 2 : head = insert_beg(head);
                        break;

            case 3 : head = insert_end(head);
                     break;

            case 4 :   printf("Enter the position : ");
                     scanf("%d",&pos);
                     head = insert_pos(head,pos);
                       break;

            case 5 : head = delete_beg(head);
                     break;
            
            case 6 : head = delete_end(head);
                     break;

            case 7 : printf("Enter the position : ");
                     scanf("%d",&pos);
                     head = delete_pos(head, pos);
                     break;

            case 8 : display(head);
                     break;


            case 9 : exit(0);

        }
    }
    return 0;
}