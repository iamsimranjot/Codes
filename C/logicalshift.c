#include<stdio.h>
#include<math.h>

int shift(int x , int n)
{
    x = x >> n;
    x = x & ~(((1 << 31) >> n) << 1);
    return x;
}
	

void main(int agrc , char* argv[])
{

    int x , n;

    sscanf(argv[1] , "%d" , &x);
    sscanf(argv[2] , "%d" , &n);

    printf("After Logical Shift : %d \n" , shift(x , n));
}
