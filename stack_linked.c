#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* start;

void push(int a)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = a;
    temp -> next = NULL;
    
    if(start == NULL){
	start = temp;
    }

    else{
	struct node* ptr = start;
	while(ptr -> next != NULL){
	    ptr = ptr -> next;
	}	
	ptr -> next = temp;
    }
}

void pop()
{
    struct node* ptr = start , * save;
    while(ptr -> next != NULL){
	save = ptr;
	ptr = ptr -> next;
    }

    save -> next = NULL;
}

void print()
{
    struct node* ptr = start;
    while(ptr != NULL){
	printf("%d " , ptr -> data);
	ptr = ptr -> next;
    }
}

void main()
{

    start = NULL;
    int a , x = 1 , n;

    while(x == 1){

	printf("Enter Your Choice : \n1. Push\n2. Pop\n3. Print Stack : ");
	scanf("%d" , &n);

	switch(n){

	    case 1:{

		printf("Enter The Number : ");
		scanf("%d" , &a);
		push(a);
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

	printf("\nYou want to continue ? 1 / 0: ");
	scanf("%d" , &x);
    }
}
