/**
Description : Detect a loop in  a singly linked list.
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

void printList(node *root){
	int k=0;
	while(root!=NULL){
		printf(" %d", root->data);
		root = root->next;
		k++;
		if(k>9)break;
		}
	printf("\n");
	}

int detectLoop(node *root){
	if(root==NULL || root->next==NULL)return 0;
	node *fast = root;
	node *slow = root;
	while(slow!=NULL && fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow)return 1;
		}
	return 0;
	}

int main(){
	node *root=makenode(1);
	root->next = makenode(2);
	root->next->next = makenode(3);
	root->next->next->next = makenode(4);
	root->next->next->next->next = root->next;
	if(detectLoop(root))printf("Loop is present");
	else printf("Loop is not present");
	return 0;
	}
