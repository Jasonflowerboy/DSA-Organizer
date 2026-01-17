#include<stdio.h>
#include<stdlib.h>

//TC -> BEST CASE/AVERAGE CASE  -> O(logn) , WORSE CASE -> UNBALANCED/SKEWED BST -> O(n)
struct node{
    int data;
    struct node *left;
    struct node *right;
};


struct node *create(int value)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory full. Exiting.. ");
        exit(0);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    printf("Node Inserted.");
    return newNode;
}

struct node *insert(struct node *root, int value)
{
    if(root == NULL)
    {
        root = create(value);
    }
    else if(value<root->data)
    {
        root->left = insert(root->left,value);
    }
    else if(value>root->data)
    {
        root->right = insert(root->right,value);
    }
    return root;
}


void inorder(struct node *root)
{
    if(root == NULL)
    {
        return ;
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}


int search(struct node *root, int key)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->data == key)
    {
        return 1;
    }
    else if (key > root->data)
    {
        return search(root->right,key);
    }
    else if (key < root->data)
    {
        return search (root->left, key);
    }
}


struct node *delete(struct node *root, int value)
{
    if(root == NULL)
    {
        printf("Element not found.");
        return NULL;
    }
    else if(value < root->data)
    {
        root->left = delete(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = delete(root->right, value);
    }
    else {    //Element found
            if(root->left == NULL && root->right == NULL)   //Case 1 : No Child
            {
                printf("Node deleted");
                free(root);
                return NULL;
            }   
            else if ( root->left != NULL && root->right == NULL)   //Case 2 : One child
            {
                struct node *temp = root->left;
                printf("Node deleted");
                free(root);
                return temp;
            }

            else if (root->right != NULL && root->left == NULL)
            {
                struct node *temp = root->right;
                printf("Node deleted");
                free(root);
                return temp;
            }

            else //case 3 - Both children. The deleted root will be replaced by its inorder successor.
            {
                struct node *temp = root->right;
                while(temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = delete(root->right, temp->data);
            }
        }
        return root;
}


void preorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
         postorder(root->left);
         postorder(root->right);
         printf("%d ",root->data);        
    }
}

int main()
{
    struct node *root = NULL;
    
    int value,key,s,found;
    while(1)
    {
        printf("\nMENU:1-Insert\n2-Search\n3-Delete\n4-Inorder\n5-Preorder\n6-Postorder\n7-Exit : ");
        scanf("%d",&s);
        switch(s)
        {
            case 1 : printf("Enter the value to insert : ");
                     scanf("%d",&value);
                     root = insert(root,value);
                     break;

            case 2 : printf("Enter the element to search : ");
                     scanf("%d",&key);
                     found = search(root,key);
                    if(found == 1)
                    {
                        printf("Element found in BST");
                    }
                    else
                    {
                        printf("Element not found in BST");
                    }
                    break;

            case 3 : printf("Enter the value to delete : ");
                     scanf("%d",&value);
                     root = delete(root,value);
                     break;
                

            case 4 : printf("INORDER -> "); 
                    inorder(root);
                     break;

                  case 5 :printf("PREORDER -> "); 
                preorder(root);
                     break;

            case 6 : printf("POSTORDER -> ");
                     postorder(root);
                     break;

            case 7 : exit(0);
        }
    }
   return 0; 
}