/**
Description : FLatten a link list level wise where each node can
* havev right and/or down pointer/s.
**/

#include <bits/stdc++.h>
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
	printf("\nPrinting Updated List : ");
	while(root!=NULL){
		printf(" %d", root->data);
		if(root->right)cout<<"right "<<root->right->data;
		root = root->down;
		}
	printf("\n");
	}

node *flattenUsing2Queue(node *root){
	if(root==NULL)return root;
	node *result = new node;
	result = NULL;
	queue<node *>first;
	queue<node *>second;
	first.push(root);
	int i=0;
	while(!first.empty() || !second.empty()){
		if(i==0){
			node *temp = new node;
			temp = first.front();first.pop();
			if(result==NULL){
				result = temp;
				if(temp->down)second.push(temp->down);
				if(temp->right)first.push(temp->right);
				}
			else{
				if(temp->down)second.push(temp->down);
				if(temp->right)first.push(temp->right);
				}
			cout<<" first "<<temp->data<<endl;
			result->down = temp;
			if(first.empty())i = 1-i;
			}
		else{
			node *temp = new node;
			temp = second.front();second.pop();
			if(temp->down)first.push(temp->down);
			if(temp->right)second.push(temp->right);
			cout<<" second "<<temp->data<<endl;
			result->down = temp;
			if(second.empty())i = 1-i;
			}
		}
	return result;
	}

int main(){
	node *root = makenode(1);
	root->right = makenode(2);
	root->right->right = makenode(3);
	root->right->right->right = makenode(4);
	root->right->right->right->right = makenode(5);
	root->right->right->right->right->right = makenode(6);
	
	root->down = makenode(7);
	root->down->down = makenode(8);
	
	root->right->right->down = makenode(9);
	root->right->right->down->down = makenode(10);
	root->right->right->down->down->down = makenode(99);
	
	root->right->right->right->down = makenode(11);
	root->right->right->right->down->right = makenode(12);
	root->right->right->right->down->down = makenode(13);
	
	printList(flattenUsing2Queue(root));
	return 0;
	}
