#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node{

	int val;
	struct node *left;
	struct node *right;
}*root = NULL;


struct node* new_node(int key){

		struct node* temp = (struct node*) malloc (sizeof(struct node));
		temp -> val = key;
		temp -> left = NULL;
		temp -> right = NULL;
		return temp;
}


struct node* insert(int key , struct node* ptr){

	if(ptr == NULL){

		return new_node(key);
	}

	else if(key < ptr -> val) {

		ptr -> left = insert(key , ptr -> left);
	}

	else if(key > ptr -> val) {

		ptr -> right = insert(key , ptr -> right);
	}

	return ptr;
}


void inorder(struct node* root){

	if(root == NULL)
		return;

	inorder(root -> left);
	printf("%d  " , root -> val);
	inorder(root -> right);
	
}

void preorder(struct node* root){

	if(root == NULL)
		return;

	printf("%d  " , root -> val);
	preorder(root -> left);
	preorder(root -> right);
}

void postorder(struct node* root){

	if(root == NULL)
		return;

	postorder(root -> left);
	postorder(root -> right);
	printf("%d  ", root -> val);
}


struct node* min_value(struct node* root){

	struct node* min = root;

	while(min -> left != NULL){

		min = min -> left;
	}

	return min;
}


struct node* max_value(struct node* root){

	struct node* max = root;

	while(max -> right != NULL){

		max = max -> right;
	}

	return max;
}


struct node* delete(int key , struct node* root){

	if(root == NULL)
		return root;

	else if(key < root -> val)
		root -> left = delete(key , root -> left);

	else if(key > root -> val)
		root -> right = delete(key , root -> right);

	else{

		//Case 1: Only one child node or no child
		if(root -> left == NULL){

			struct node* temp = root -> right;
			free(root);
			return temp;
		}

		else if(root -> right == NULL){

			struct node* temp = root -> left;
			free(root);
			return temp;
		}


		// Case 2 : having both childs
		else{

			struct node* temp = min_value(root -> right);
			root -> val = temp -> val;
			root -> right = delete(temp -> val , root -> right);

		}
	}

	return root;
}



int Ceil (struct node* root , int x){

	if(root == NULL)
		return -1;

	else if(root -> val == x)
		return (root -> val);

	else if(root -> val < x)
		return Ceil(root -> right , x);

	else{

		int ceil = Ceil(root -> left , x);
		return (ceil >= x) ? ceil : root -> val;
	}
}


bool isBST(struct node* root){

	static struct node* prev = NULL;

	if(root != NULL){

		if(!(isBST(root -> left)))
			return 0;

		if(prev != NULL && root -> val <= prev -> val)
			return 0;

		prev = root;

		return isBST(root -> right);

	}

	return 1;
}


int main(){

	root = insert(50 , root);  //inserts the value in the BST
	insert(30 , root);
	insert(20 , root);
	insert(40 , root);
	insert(70 , root);
	insert(60 , root);
	insert(80 , root);

	//inorder(root);  //Does inorder traversal

	//preorder(root);  //Does preorder traversal

	//postorder(root);  //Does postorder traversal

	//delete(50 , root);  //deletes the node of the value given

	//min_value(root);  //returns the node with minimum value

	//max_value(root) -> val;  //return the node with the max value
	
	//Ceil(root , 25);  //returns the Ceil value of the input form the BST

	//isBST(root);  //returns 0 or 1 corresponding to if the tree is a valid BST or not

	return 0;

}