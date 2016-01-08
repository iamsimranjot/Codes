#include<stdio.h>
#include<stdlib.h>

int top = -1 , *arr , n;

void push(int x)
{
    if(top == ((n / 2) - 1)){
	arr = (int*)realloc(arr , (2 * n * sizeof(int)));
	n = n * 2;
	printf("Double Memory Allocated\n");
    }
    arr[++top] = x;
}

int pop()
{
    if(top == -1){
	printf("Stack Empty\n");
    }

    else{
        int temp = arr[top];
        top--;
        return temp;
    }
}

void print()
{
    int i;

    for(i = 0 ; i <= top ; i++){
	printf("%d " , arr[i]);
    }
}

void main(int argc , char* argv[])
{

    int a , temp , y = 1;

    sscanf(argv[1] , "%d" , &n);
    arr = (int*)malloc(n * sizeof(int));

    while(y == 1){

    printf("Enter Your Choice : \n1.Push\n2.Pop\n3.Print : ");
    scanf("%d" , &a);

    switch(a){

	case 1:{
	    printf("Enter Element : ");
	    scanf("%d" , &temp);
	    push(temp);
	    break;
	}

	case 2:{
	    pop();
	    break;
	}

	case 3:{
	    print();
	}
    }

    printf("You want to continue ? 1 / 0 : ");
    scanf("%d" , &y);
  }

}
