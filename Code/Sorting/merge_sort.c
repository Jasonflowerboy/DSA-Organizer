#include<stdio.h>
void mergesort(int *arr, int low, int high);
void merge(int *arr, int low, int mid, int high);


//TC -> Best, Average and Worst Case -> O(nlogn)
void mergesort(int *arr, int low, int high)
{
    int mid;
    if(low == high)
    {
        return;
    }
    else
    {
        mid = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void merge(int *arr, int low, int mid, int high)
{
    int size = (high-low)+1;
    int temp[size];
    int k = 0; // indexing for our temp array.
    int left = low;
    int right = mid+1;
    while(left<=mid && right <= high)
    {
        if(arr[left]<= arr[right])
        {
            temp[k] = arr[left];
            left++;
            k++;
        }
        else //arr[right] is smaller so we add this to the temp array
        {
            temp[k] = arr[right];
            right++;
            k++;
        }
    }
    //coming out of this loop means, that one side has been exhausted, so we just add the other half directly to the temp array.
    while(left<=mid)
    {
        temp[k] = arr[left];
        left++;
        k++;
    }

    while(right<=high)
    {
        temp[k] = arr[right];
        right++;
        k++;
    }
    //because indepth of recursion, low changes so for the original we put ther sorted array from low to high but our
    //temp array always starts from zero.
    for(int i=low; i<=high; i++)
    {
        arr[i] = temp[i-low];
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
    mergesort(arr,0,n-1);
    display(arr,n);
    return 0;
}