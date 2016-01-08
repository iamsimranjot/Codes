#include<stdio.h>

void main(int agrc , char* argv[])
{

    int x , i = 0 , count = 0;

    sscanf(argv[1] , "%d" , &x);
    
    while(i < 32 && x != 0){

	if(x & 1){
	    count++;
	}
	x = x >> 1;
	i++;
    }

    printf("No. of Set Bits are : %d\n" , count);
}
