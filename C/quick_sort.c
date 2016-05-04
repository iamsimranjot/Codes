#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>

struct timeval t1 , t2 , t3;

void quick(int arr[] , int beg , int end)
{
    if(beg < end){

	int p = sort(arr , beg , end);
	quick(arr , beg , p - 1);
	quick(arr , p + 1 , end);
    }
}

int sort(int arr[] , int beg , int end)
{
    int pivot = arr[end];
    int pindex = beg;
    int i , temp;

    for(i = beg ; i < end ; i++){

	if(arr[i] <= pivot){

	    temp = arr[i];
	    arr[i] = arr[pindex];
	    arr[pindex] = temp;
	    pindex++;
	}
    }
    
    temp = arr[pindex];
    arr[pindex] = arr[end];
    arr[end] = temp;

    return pindex;
}




void main(int argc , char* argv[])
{

    gettimeofday(&t1 , NULL);

    int *arr , n , i;
    long int time;

    sscanf(argv[1] , "%d" , &n);
    arr = (int*)malloc(n * sizeof(int));

    for(i = 0 ; i < n ; i++){

	arr[i] = i;
    }

    quick(arr , 0 , n - 1);

    gettimeofday(&t2 , NULL);

    t3.tv_sec = t2.tv_sec - t1.tv_sec;
    t3.tv_usec = t2.tv_usec - t1.tv_usec;
    time = t3.tv_sec * pow(10 , 6) + t3.tv_usec;

    printf("Running Time is %ld\n" , time);
}
