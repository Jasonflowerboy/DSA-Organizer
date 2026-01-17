#include<stdio.h>

int fibo(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return ((fibo(n-1)) + fibo(n-2));
    }
}

int main(void)
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    printf("The Fibonacci series is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d  ",fibo(i));
    }
    return 0;
}