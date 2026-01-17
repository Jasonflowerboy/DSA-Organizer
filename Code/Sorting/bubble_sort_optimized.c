#include<stdio.h>

//TC - BEST CASE - O(n) and WORST/AVERAGE Case O(n^2).

void display(int *arr, int n)
{
    printf("The array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
printf("\n");
}



void bubblesort(int *arr, int n )
{
    int i,j,temp;
    int swapped;
    for(int i = n-1; i>=1; i--)
    {
        swapped = 0;
        for(int j=0; j<=i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapped = 1;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(swapped == 0)
        {
            break;
        }
    }
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
    bubblesort(arr,n);
    display(arr,n);
    return 0;
}