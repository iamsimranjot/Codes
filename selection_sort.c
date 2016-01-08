#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>

struct timeval t1 , t2 , t3;

void main(int argc , char* argv[])
{

    gettimeofday(&t1 , NULL);   

    int n ,* arr , i , j , temp , min;
    long int time;

   /* printf("Enter the number of Elements : ");
    scanf("%d" , &n);*/

   /* printf("Enter the Elements : ");*/

    sscanf(argv[1] , "%d" , &n);
    arr = malloc(n * sizeof(int));

    for(i = 0 ; i < n ; i++){
	arr[i] = rand() % n;
	}

    for(i = 0 ; i < n - 1  ; i++){

	for(j = i + 1 ; j < n - 1 ; j++){
            
	    if(arr[j] > arr[j + 1]){
	        
		min  = j + 1;
	    }
	}

	    if(arr[i] > arr[min]){
	        temp = arr[i];
	        arr[i] = arr[min];
	        arr[min] = temp;
	    }
    }

    gettimeofday(&t2 , NULL);
    t3.tv_sec = t2.tv_sec - t1.tv_sec;
    t3.tv_usec = t2.tv_usec - t1.tv_usec;

    time = t3.tv_sec * pow(10 , 6) + t3.tv_usec;

    printf("Time Taken is %ld\n" , time); 
   /* printf("Array Aftr Selection Sort is : \n");
    for(i = 0 ; i < n ; i++){
	printf("%d  " , arr[i]);
    }*/
}

