#include<stdio.h>
//TC -> ALL CASES O(n^2)

void selectionsort(int *arr, int n)
{
    int i,j,small,temp;
    for(int i = 0; i<=n-2; i ++)
    {
        small = i;
        for(int j = i+1;j<=n-1;j++)
        {
            if(arr[j]<arr[small])
            {
                small = j;
            }
        }
        if(i != small)
        {
            temp = arr[i];
            arr[i] = arr[small];
            arr[small] = temp;
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
    selectionsort(arr,n);
    display(arr,n);
    return 0;
}