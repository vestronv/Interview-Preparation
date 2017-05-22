/**
Description : Reverse a linked list in group of K elements.
* Ex. 1 2 3 4 5 6 7 8 in group K=3 is => 3 2 1 6 5 4 8 7
**/

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
	};
node *makenode(int data){
	node *temp = new node();
	temp->data = data;
	temp->next = NULL;
	return temp;
	}

void die(node **root){
	if(*root==NULL)return;
	die(&( (*root)->next ));
	free(*root);
	}

void printList(node *root){
	printf("\nPrinting Updated List : ");
	while(root!=NULL){
		printf(" %d", root->data);
		root = root->next;
		}
	printf("\n");
	}

node *reverseByK(node *root, int k){
	node *cur=root,*prev=NULL,*nxt=NULL;
	int count=0;
	while(cur!=NULL && count<k){
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur= nxt;
		count++;
		}
	if(nxt!=NULL)root->next = reverseByK(nxt, k);
	return prev;
	}

int main(){
	int n,i,ele,k;
	printf("Enter how many many nodes to be created : ");
	scanf("%d",&n);
	node *root=new node(),*current;
	for(i=0; i<n; i++){
		printf("Enter node value : ");
		scanf("%d",&ele);
		if(i==0){
			root = makenode(ele);
			current = root;
			}
		else{
			node *temp = makenode(ele);
			current->next = temp;
			current = temp;
			}
		}
	printf("Enter value of K : ");
	scanf("%d",&k);
	printList(reverseByK(root,k));
	die(&root);
	return 0;
	}
