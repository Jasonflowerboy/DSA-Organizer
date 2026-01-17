#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


struct node *create(struct node *head, int n)
{
    struct node *newNode;
    struct node *tail = head;
    int value;
    for(int i=1;i<=n;i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode == NULL)
        {
            printf("Memory is full. Exiting..");
            exit(0);
        }
        printf("Enter the value of node %d :",i);
        scanf("%d",&value);
        newNode->data = value;
        newNode->next = NULL;
        printf("Node %d created.\n",i);
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void display(struct node *head)
{
    if(head == NULL)
    {
        printf("The LinkedList is empty.");
        return ;
    }
    struct node *temp = head;
    printf("The LinkedList is -> ");
    while(temp != NULL)
    {
        printf(" %d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}


struct node* insert_beg(struct node *head)
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
    printf("Node inserted at beginning.");
    if(head == NULL)
    {
        newNode -> next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct node *insert_end(struct node *head)
{
    int value;
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory full. Exiting..");
        exit(0);
    }
    printf("Enter the value to insert : ");
    scanf("%d",&value);
    newNode->data = value;
    newNode->next = NULL;
    printf("Node successfully inserted at the end.");
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp;
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
struct node* delete_beg(struct node*head)
{
    if(head == NULL)
    {
        printf("The LinkedList is already empty.");
    }
    else
    {
        struct node *temp;
        temp = head;
        head = head->next;
        free(temp);
        printf("Node successfully deleted.");
    }
    return head;
}

struct node*delete_end(struct node* head)
{
    if(head == NULL)
    {
        printf("The LinkedList is already empty");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Node successfully deleted.");
    }
    else{
        struct node *temp, *prev;
        temp = prev = head;
        while(temp->next!=NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        prev->next = NULL;
         printf("Node successfully deleted.");
    }
    return head;
}

struct node *insert_pos(struct node *head,int pos)
{
    struct node *newNode;
    int value;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory Full. Exiting..");
        exit(0);
    }

    printf("Enter the value to insert : ");
    scanf("%d",&value);
    newNode->data = value;

    if(pos==1)
    {
        newNode->next = head;
        head = newNode;
        printf("Node successfully inserted");
    }
    else
    {
        struct node *temp;
        temp = head;
        for(int i=1; i<pos-1 && temp!=NULL; i++)
        {
            temp = temp->next;
        }

        if(temp == NULL)
        {
            printf("Invalid Position Entered.");
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node successfully inserted.");
        }
    }
    return head;
}

struct node *delete_pos(struct node *head, int pos)
{
    if(head == NULL)
    {
        printf("The LinkedList is already empty");
    }
    else if (pos == 1)
    {
        struct node *temp;
        temp = head;
        head = head->next;
        free(temp);
        printf("Node successfully deleted.");
    }
    else
    {
        struct node *temp, *prev;
        temp = prev = head;
        for(int i=1; i<pos && temp!= NULL; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL)
        {
            printf("Invalid position entered");
        }
        else
        {
            prev->next = temp->next;
            free(temp);
            printf("Node successfully deleted.");
        }
    }
    return head;
}


struct node *reverse (struct node *head)
{
    struct node *prev, *curr, *temp;
    prev = NULL;
    temp = curr = head;
    while(temp!=NULL)
    {
        temp = temp->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

int count(struct node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    int count = 0;
    struct node *temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void main()
{
    struct node *head = NULL;
    int n,value,s,counter,pos;
    while(1)
    {
         printf("\n\nMENU:1-Create\n2-Insert at beginning\n3-Insert at end\n4-Delete at beginning\n5-Delete at end\n6-Display\n7-Insert at pos\n8-Delete at Pos\n9-Reverse\n10-Count the number of nodes\n11-Exit : ");
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

            case 4 : head = delete_beg(head);
                   break;

            case 5 : head = delete_end(head);
                     break;

            case 6: display(head);
                     break;

            case 7 : printf("Enter the position to insert the element in : ");
                    scanf("%d",&pos);
                 head = insert_pos(head,pos);
                  break;
                  
            case 8 : printf("Enter the position to delete the element from : ");
                     scanf("%d",&pos);
                     head = delete_pos(head,pos);
                     break;

            case 9 : head = reverse(head);
                     break;

            case 10 : printf("The number of nodes in the LinkedList is : %d",count(head));
                     break;

            case 11 : exit(0);

        }
    }
}