#include<stdio.h>
#include<stdlib.h>

void create(int *arr, int n)
{
    printf("Enter %d elements into the array :",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
}

void display(int *arr, int n)
{
    if(n==0)
    {
        printf("The List is empty");
        return;
    }
    printf("The array is : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}



int insert(int *arr, int n, int pos, int num)
{
    for(int i=n-1; i>=pos; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos] = num;
    n++;
    return n;
}


int delete(int *arr, int n, int pos)
{
    for(int i=pos; i<n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    n--;
    return n;
}



int main()
{
    int arr[100];
    int n;
    int pos,num,s;
    while(1)
    {
    printf("Menu:1-Create\n2-Display\n3-Insert at Pos\n4-Delete at Pos\n5-Exit : \n");
    scanf("%d",&s);
     switch(s)
     {
        case 1 : printf("Enter size of the array : ");
            scanf("%d",&n);
            create(arr,n);
            break;

        case 2 : display(arr,n);
                 break;

        case 3 : printf("Enter the value to insert : ");
            scanf("%d",&num);
            printf("Enter the position to insert at : ");
            scanf("%d",&pos);
            n = insert(arr,n,pos,num);
            break;

        case 4 : printf("Enter the position to delete from : ");
                 scanf("%d",&pos);
                n = delete(arr,n,pos);
                break;
            
        case 5 : exit(0);
        }

    }
  return 0;
}