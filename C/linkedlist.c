#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *link;
} *start = NULL;


void insert(){

	struct node *new , *ptr;
	int a;

	new = (struct new *) malloc (sizeof(struct node));

		printf("Enter the value to be Inserted : ");
		scanf("%d" , &a);

		new -> val = a;
		new -> link = NULL;

	if(start == NULL) {

		start = new;
	}

	else {

		ptr = start;

		while(ptr -> link != NULL){

			ptr = ptr -> link;
		}

		ptr -> link = new;
		
	}
}

insert_beg(){

	struct node *new , *temp;
	int a;

	new = (struct new *) malloc (sizeof(struct node));

	printf("Enter the value to be Inserted at the Beginning : ");
	scanf("%d" , &a);

	new -> val = a;

	if(start == NULL){

		start = new;
		new -> link = NULL;

	}

	else {

		temp = start;
		start = new;
		new -> link = temp;
	}
}

void insert_btw(){

	struct node *ptr , *temp , *new;
	int a , p , i;

	printf("Enter the position where to be inserted : ");
	scanf("%d" , &p);

	printf("Enter the value to be Inserted : ");
	scanf("%d" , &a);

	new = (struct new *) malloc (sizeof(struct node));

	new -> val = a;
	new -> link = NULL;

	ptr = start;

	for(i = 0 ; i < p - 1 ; i++){

		ptr = ptr -> link;
	}

	temp = ptr -> link;

	ptr -> link = new;
	new -> link = temp;

}

void print(){

	struct node *ptr;
	ptr = start;

	while(ptr != NULL){

		printf("%d   ", ptr -> val);
		ptr = ptr -> link;
	}

	printf("\n");
}

void delete_beg(){

	struct node *temp;

	temp = start;
	start = start -> link;

	printf("First Node Sucessfully Deleted !\n");
	free(temp);
}

void delete_last(){

	struct node *ptr , *temp;

	ptr = start;

	while(ptr -> link != NULL){

		temp = ptr;
		ptr = ptr -> link;
	}

	temp -> link = NULL;

	printf("Last Node Sucessfully Deleted !\n");

	free(ptr);
}


void delete_btw(){

	struct node *ptr , *prev , *next;
	int p , i;

	printf("Enter the position where you want to delete the node : ");
	scanf("%d" , &p);

	ptr = start;

	for(i = 0 ; i < p - 1 ; i++){

		prev = ptr;
		ptr = ptr -> link;
	}

	next = ptr -> link;

	prev -> link = next;

	printf("Node at %d position Deleted Sucessfully! " , p);

	free(ptr);

}



int main() {

	insert(); //by default inserts values at the end

	insert_beg(); //inserts element at the beginning of the list

	insert_btw(); //inserts element at the given position in the list

	delete_beg(); //delets the first element of the list

	delete_last(); //deletes the last element of the list

	delete_btw(); // deletes element at the given position

	return 0;
}
