/**
Description : Connect nodes at same level.
**/
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left,*right,*nextRight;
	};

node *makenode(int data){
	node *temp = new node();
	temp->data = data;
	temp->left = temp->right = temp->nextRight = NULL;
	return temp;
	}

void print(node *root){
	if(!root)return;
	node *temp = (root->left)?root->left:root->right;
	while(root!=NULL){
		printf(" %d ",root->data);
		root = root->nextRight;
		}
	printf("\n");
	print(temp);
	}

node *getMy(node *root, int isRight){
	node *temp=root,*ret=NULL;
	//cout<<"I am "<<root->data<<" and my nR is "<<((root->nextRight)?root->nextRight->data:-1)<<endl;
	if(isRight){
		while(root->nextRight != NULL){
			root = root->nextRight;
			if(root->left){return root->left;}
			if(root->right){return root->right;}
			}
		if(temp==root){
			ret = NULL;
			}
		else{
			ret = (root->left)?root->left:root->right;
			}
		}
	else{
		if(root->right){
			ret = root->right;
			}
		else{
			while(root->nextRight!=NULL){
				if(root->left){ret = root->left;break;}
				if(root->right){ret = root->right;break;}
				}
			}
		}
	return ret;
	}

void connNow(node *root){
	if(!root)return ;
	node *temp = root;
	while(root!=NULL){
		if(root->left){
			root->left->nextRight = getMy(root,0);
			}
		if(root->right){
			root->right->nextRight = getMy(root,1);
			}
		root = root->nextRight;
		}
	root = temp;
	connNow(root->left);
	connNow(root->right);
	}

void solve(node *root){
	root->nextRight = NULL;
	connNow(root);
	}

int main(){
	node *root = makenode(1);
	root->left = makenode(2);
	root->right = makenode(3);
	
	root->left->left = makenode(4);
	root->left->right = makenode(5);
	root->right->left = makenode(6);
	root->right->right = makenode(7);
	
	root->left->left->left = makenode(8);
	root->left->left->right = makenode(9);
	root->right->right->left = makenode(10);
	root->right->right->right = makenode(11);
	
	solve(root);
	printf("\n\nList in level order is : \n");
	print(root);
	return 0;
	}
