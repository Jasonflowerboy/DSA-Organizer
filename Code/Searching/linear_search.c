#include<stdio.h>

int linearsearch(int *arr, int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == key)
        {
            return i;
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
    printf("Enter %d elements into the array : ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter element to search : ");
    scanf("%d",&key);
    int pos = linearsearch(arr,n,key);
    if(pos == -1)
    {
        printf("Element not found.");
    }
    else {
        printf("Element found in index %d",pos);
    }
    return 0;
}