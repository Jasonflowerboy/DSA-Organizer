#include<stdio.h>

void TOH(int n, int S, int A, int D)
{
    if(n>0)
    {         /*3 S A D
                2 S D A
                1 S A D              I I I
                                          X
                                          Y
                                          Z 
                
                                                                            */                                                                  
        TOH(n-1,S,D,A);
        printf("Move Disk %d from Rod %d to Rod %d\n",n,S,D);
        TOH(n-1,A,S,D);  //1 D S A ->  1 D to A 
                           // 2 A S D 
                        
                           //1 S A D
                           //1 from S to D
    }
}

int main(void)
{
    int S,A,D,n;
    printf("Enter the number of disks : ");
    scanf("%d",&n);
    printf("We have Three Rods. 1, 2 and 3.");
    printf("Choose the Source Rod : ");
    scanf("%d",&S);
    printf("Choose the Destination Rod : ");
    scanf("%d",&D);
    A = 6-(S+D);
    TOH(n,S,A,D);
}