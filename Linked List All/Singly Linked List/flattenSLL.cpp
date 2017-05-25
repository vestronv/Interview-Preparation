/**
Description : Given list with right and down pointers which is sorted in down and right order.
* Flatten it to make a single dimension sorted list.
* NOTE : aprt from first level no nodes are rightly connected...they are just down.
**/

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *right,*down;
	};
node *makenode(int data){
	node *temp = new node();
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	return temp;
	}

void die(node **root){
	if(*root==NULL)return;
	die(&( (*root)->right ));
	die(&( (*root)->down ));
	free(*root);
	}

void printList(node *root){
	while(root!=NULL){
		printf(" %d", root->data);
		root = root->down;
		}
	printf("\n");
	}

node *merge(node *a, node *b){
	if(a==NULL)return b;
	if(b==NULL)return a;
	node *ret;
	if(a->data < b->data){
		ret = a;
		ret->down = merge(a->down,b);
		}
	else{
		ret = b;
		ret->down = merge(a,b->down);
		}
	return ret;
	}

node *flatten(node *root){
	if(root==NULL || root->right==NULL)return root;
	return merge(root,flatten(root->right));//right ko flat karne k bad mere kar do root k sath...
	}

int main(){
	node *root = new node;
	root = makenode(5);
	root->right = makenode(10);
	root->right->right = makenode(19);
	root->right->right->right = makenode(28);
	root->down = makenode(7);
	root->down->down = makenode(8);
	root->down->down->down = makenode(30);
	root->right->down = makenode(20);
	root->right->right->down = makenode(22);
	root->right->right->down->down = makenode(50);
	root->right->right->right->down = makenode(35);
	root->right->right->right->down->down = makenode(40);
	root->right->right->right->down->down->down = makenode(45);
	printf("\nOrigin List : ");
	printList(root);
	printf("\nFlattened List is : ");
	printList(flatten(root));
	die(&root);
	return 0;
	}
