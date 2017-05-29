/**
Description : Sort a link list of 0's 1's and 2's only. 
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

void die(node *root){
	if(root==NULL)return;
	die(root->next);
	free(root);
	}

void printList(node *root){
	printf("\nUpdated list : ");
	while(root!=NULL){
		printf(" %d ",root->data);
		root = root->next;
		}
	printf("\n");
	}

node *sort012(node *root){
	node *temp = root;
	int n0 = 0, n1 = 0, n2 = 0;
	while(temp!=NULL){
		if(temp->data==0)n0++;
		else if(temp->data==1)n1++;
		else if(temp->data==2)n2++;
		temp = temp->next;
		}
	temp = root;
	while(temp!=NULL){
		if(n0)temp->data = 0, n0--;
		else if(n1)temp->data = 1, n1--;
		else if(n2)temp->data = 2, n2--;
		temp = temp->next;
		}
	return root;
	}

int main(){
	int n,ele;
	printf("Enter number of nodes in first SLL : ");
	scanf("%d",&n);
	node *root=new node, *current;
	root = NULL;
	for(int i=0; i<n; i++){
		printf("Enter node value : ");
		scanf("%d",&ele);
		if(i==0){
			root = makenode(ele);
			current = root;
			}
		else{
			node *temp = makenode(ele);
			current->next = temp;
			current = current->next;
			}
		}
	printList(sort012(root));
	return 0;
	}
