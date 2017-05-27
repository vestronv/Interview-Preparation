/**
Description : Pair Wise swap a Singly linked list.
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

node *pairWiseSwap(node *root){
	if(root==NULL || root->next==NULL)return root;
	node *prev = root, *cur = root->next;
	root = cur;
	while(1){
		node *nxt = cur->next;
		cur->next = prev;
		if(nxt==NULL || nxt->next == NULL){
			prev->next = nxt;
			break;
			}
		prev->next = nxt->next;
		prev = nxt;
		cur = prev->next;
		}
	return root;
	}

int main(){
	int n,ele;
	printf("How many nodes? : ");
	scanf("%d",&n);
	node *root = new node,*current;
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
			current = temp;
			}
		}
	printList(pairWiseSwap(root));
	return 0;
	}
