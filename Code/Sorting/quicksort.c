#include<stdio.h>

int partition(int *arr, int low, int high);
void quicksort(int *arr, int low, int high);

void quicksort(int *arr, int low, int high)
{
    if(low<high)
    {
  int partition_index = partition(arr,low,high);
    quicksort(arr,low,partition_index-1);
    quicksort(arr,partition_index+1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = low;
    int i = low;
    int j = high;
    int temp;
    while(i<j) //as soon as i = j, we stop
    {
        while(arr[i]<=arr[pivot] && i <= high - 1)
        {
            i++;
        }
        while(arr[j]>arr[pivot] && j >= low+1)
        {
            j--;
        }
        if(i<j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //this loop stopping means j is the same as i, so on the right of j, we have all elements bigger than pivot element in unsorted order
    // and on the right side of j all elements that are smaller or equal to pivot element in unsorted order.
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    return j;
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
    quicksort(arr,0,n-1);
    display(arr,n);
    return 0;
}