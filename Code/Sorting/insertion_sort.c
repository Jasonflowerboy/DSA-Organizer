#include<stdio.h>
void insertionsort(int *arr, int n)
{
    int i,j,temp;
    for(i=1;i<=n-1;i++)
    {
        j = i;
        while(j>0 && arr[j-1]>arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

void display(int *arr, int n)
{
    printf("The array is : ");
    for(int i=0; i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter size of the array : ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements into the array  :",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before Sorting : ");
    display(arr,n);
    printf("After Sorting : ");
    insertionsort(arr,n);
    display(arr,n);
    return 0;
}