#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>

int count = 0;
struct timeval t1 , t2 , t3;

void merge(int arr[] , int beg , int mid , int end)
{
    int i , j , k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int temp1[n1] , temp2[n2];

    for(i = 0 ; i < n1 ; i++){
	temp1[i] = arr[beg + i];
    }

    for(i = 0 ; i < n2 ; i++){
	temp2[i] = arr[mid + 1 + i];
    }

    i = 0 ;
    j = 0;
    k = beg;

    while(i < n1 && j < n2){

	if(temp1[i] <= temp2[j]){
	    arr[k] = temp1[i];
	    i++;
	}

	else{
	    count = count + (mid - i + 1);
	    arr[k] = temp2[j];
	    j++;
	}
	k++;
    }

    while (i < n1){

	arr[k] = temp1[i];
	i++;
	k++;
    }

    while (j < n2){

	arr[k] = temp2[j];
	j++;
	k++;
    }
}

void mergesort(int arr[] , int beg , int end)
{
    if(beg < end){

	int mid = (beg + end) / 2;
	mergesort(arr , beg , mid);
	mergesort(arr , mid + 1 , end);
	merge(arr , beg , mid , end);
    }
}


void main(int argc , char* argv[])
{

    gettimeofday(&t1 , NULL);

    int n , *arr , i;
    long int time;

    sscanf(argv[1] , "%d" , &n);
    arr = malloc(n * sizeof(int));

    for(i = 0 ; i < n ; i++){

	scanf("%d" , &arr[i]);
    }

    mergesort(arr , 0 , n - 1);

    gettimeofday(&t2 , NULL);

    t3.tv_sec = t2.tv_sec - t1.tv_sec;
    t3.tv_usec = t2.tv_usec - t1.tv_usec;
    time = t3.tv_sec * pow(10 , 6) + t3.tv_usec;

    printf("Running Time : %ld %d\n" , time , count);
}  
