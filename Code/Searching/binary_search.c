#include<stdio.h>

int binarysearch(int *arr, int n, int key)
{
    int low = 0;
    int high = n-1;
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == key)
        {
            return mid; // found
        }
        else if (arr[mid] < key) //serach on the right side (greater side) then
        {
            low = mid +1;
        }
        else if (arr[mid] > key)  //search on the left side (smaller side)
        {
            high = mid -1;
        }
    }   
    return -1;
}

int main(void)
{
    int n;
    printf("Enter size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements into the array : (in sorted order : )",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter element to search : ");
    scanf("%d",&key);
    int pos = binarysearch(arr,n,key);
    if(pos == -1)
    {
        printf("Element not found.");
    }
    else {
        printf("Element found in index %d",pos);
    }
    return 0;
}