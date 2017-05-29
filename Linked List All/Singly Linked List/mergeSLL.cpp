/**
Description : Merge two linked list alternatively selecting nodes from both. 
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

node *mergeAlternate(node *a, node *b){
	if(a==NULL)return b;
	if(b==NULL)return a;
	node *ac = a, *bc = b, *nha = a, *nhb = b;
	node *an,*bn;
	while(ac!=NULL && bc!=NULL){
		an = ac->next;
		bn = bc->next;
		ac->next = bc;
		bc->next = an;
		ac = an;
		bc = bn;
		}
	if(ac==NULL)return nhb;
	return nha;
	}

int main(){
	int n,ele;
	printf("Enter number of nodes in first SLL : ");
	scanf("%d",&n);
	node *root1=new node, *root2=new node, *current;
	root1 = NULL;
	root2 = NULL;
	for(int i=0; i<n; i++){
		printf("Enter node value : ");
		scanf("%d",&ele);
		if(i==0){
			root1 = makenode(ele);
			current = root1;
			}
		else{
			node *temp = makenode(ele);
			current->next = temp;
			current = current->next;
			}
		}
	printf("Enter number of nodes in second SLL : ");
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		printf("Enter node value : ");
		scanf("%d",&ele);
		if(i==0){
			root2 = makenode(ele);
			current = root2;
			}
		else{
			node *temp = makenode(ele);
			current->next = temp;
			current = current->next;
			}
		}
	printList(mergeAlternate(root1,root2));
	return 0;
	}
