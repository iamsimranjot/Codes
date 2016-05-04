#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>

struct timeval t1 , t2 , t3;

void main(int argc , char* argv[])
{
    gettimeofday(&t1 , NULL);

    int n , *arr , temp , i , j , var;
    long int time;

    sscanf(argv[1] , "%d" , &n);
    arr = malloc((n + 1) * sizeof(int));

    arr[0] = -99999;

    for(i = 1 ; i <= n ; i++){
	arr[i] = n - i;
    }

    for(i = 1 ; i <= n ; i++){

    temp = arr[i];
    var = i - 1;

	while(var > 0 && temp < arr[var]){

	    arr[var + 1] = arr[var];
	    var--;
	    }

	    arr[var + 1] = temp;
	}
    
    gettimeofday(&t2 , NULL);
    
    t3.tv_sec = t2.tv_sec - t1.tv_sec;
    t3.tv_usec = t2.tv_usec - t1.tv_usec;
    time = t3.tv_sec * pow(10 , 6) + t3.tv_usec;

    printf("Running Time is %ld\n " ,time);
}	
