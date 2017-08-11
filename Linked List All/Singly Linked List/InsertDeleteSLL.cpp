/**
Description : Insertion and Deletion from a Singly linked list.
**/

#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>//wow
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
	root = root->next;
	printf("\nPrinting Updated List : ");
	while(root!=NULL){
		printf(" %d", root->data);
		root = root->next;
		}
	printf("\n");
	}

void delValue(node *root, int value){
	int flag = 0;
	node *temp;
	temp = root->next;
	while(temp!=NULL){
		if(temp->data == value){
			flag = 1;
			if(temp->next==NULL)free(temp);//temp=NULL;
			else{
				temp->data = (temp->next)->data;
				node *deleteIt = temp->next;
				temp->next = deleteIt->next;
				free(deleteIt);
				}
			}
		temp = temp->next;
		}
	if(flag)printf("\nNode successfully deleted.");
	else printf("\nCan't find such node.");
	}

int delNode(node *root, int first){
	int ret = -1;
	if(root->next == NULL){
		printf("Underflow");
		return ret;
		}
	if(!first){//delete first node
		node *deleteIt = root->next;
		root->next = deleteIt->next;
		ret = deleteIt->data;
		free(deleteIt);
		}
	else{//delete last node
		node *temp = root->next;
		while(temp->next!=NULL){
			temp = temp->next;
			}
		ret = temp->data;
		free(temp);//temp=NULL;//i know some memory issue is here :P
		}
	return ret;
	}

int main(){
	int n,ele,choice;
	printf("How many nodes you want to create : ");
	scanf("%d",&n);
	//Make root node that points to first node
	node *root=new node(), *current;
	for(int i=0; i<n; i++){
		printf("Enter node value : ");
		scanf("%d",&ele);
		node *temp = makenode(ele);
		//insertion at the end
		if(i==0){
			root->next = temp;
			}
		else{
			current->next = temp;
			}
		current = temp;
		}
	printf("Please enter :\n(1) Delete by Value \n(2) Delete Last node\n(3) Delete First node\n");
	scanf("%d",&choice);
	switch(choice){
	//delete by value
	case 1:
		printf("Enter value : ");
		int val;
		scanf("%d",&val);
		delValue(root, val);
		break;
	//delete last node
	case 2:
		if(int  p = delNode(root, 1) != -1)printf("\nDeleted node = %d",p);//parameter 0 indicates last node to be deleted otherwise first node deleted
		break;
	//delete first node
	case 3:
		if(int p = delNode(root, 0) != -1)printf("\nDeleted node = %d",p);
		break;
	default:
		printf("Wrong choice see you in heaven.");
	}
	printList(root);
	die(&root);
	printf("\n\n**********************************THE END**********************************");
	return 0;
	}

