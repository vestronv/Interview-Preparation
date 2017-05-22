/**
Description : Given two sorted lists merge them in sorted list with no extra node creation.
**/

#include<bits/stdc++.h>
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
	while(root!=NULL){
		printf(" %d", root->data);
		root = root->next;
		}
	printf("\n");
	}

node *mergeNsort(node **root1, node **root2){
	if(*root1 == NULL && *root2 == NULL)return NULL;
	if(*root1==NULL){return *root2;}
	else if(*root2==NULL)return *root1;
	if( (*root1)->data <= (*root2)->data ){
		(*root1)->next = mergeNsort(&((*root1)->next), root2);
		return *root1;
		}
	else{
		(*root2)->next = mergeNsort(root1, &((*root2)->next));
		return *root2;
		}
	}

int main(){
	int n,i,ele;
	printf("Enter how many many nodes in first list : ");
	scanf("%d",&n);
	node *root1=new node(),*current;
	root1=NULL;
	for(i=0; i<n; i++){
		printf("Enter node value : ");
		scanf("%d",&ele);
		if(i==0){
			root1 = makenode(ele);
			current = root1;
			}
		else{
			node *temp = makenode(ele);
			current->next = temp;
			current = temp;
			}
		}
	printf("Enter how many many nodes in second list : ");
	scanf("%d",&n);
	node *root2=new node();
	root2=NULL;
	for(i=0; i<n; i++){
		printf("Enter node value : ");
		scanf("%d",&ele);
		if(i==0){
			root2 = makenode(ele);
			current = root2;
			}
		else{
			node *temp = makenode(ele);
			current->next = temp;
			current = temp;
			}
		}
	printf("\nFirst list : ");
	printList(root1);
	printf("\nSecond list : ");
	printList(root2);
	printf("\nMerged and sorted list : ");
	printList(mergeNsort(&root1,&root2));
	die(&root1);
	die(&root2);
	return 0;
	}
