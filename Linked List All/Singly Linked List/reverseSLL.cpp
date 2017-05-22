/**
Description : Reverse's a singly linked list.
**/

void reverseNonRecursive(node *root){
	if(root==NULL)return ;
	node *temp,*previous=NULL;
	while(temp!=NULL){
		temp = root->next;
		root->next = previous;
		previous = root;
		//cout<<" hi "<<root->data;//if u uncooment this it prints correct answer..memory issue i gues
		if(temp->next!=NULL)root = temp;
		else {temp->next = root; root = temp; root->next = previous; break;}
		}
	printList(root);
	}

node *reverseRecursive(node *root){
	if(root==NULL || root->next == NULL)return root;
	node *current = reverseRecursive(root->next);
	root->next->next = root;
	root->next = NULL;
	return current;
	}

int reverseRecursivePrintable(node **root, node *cur, node *prev){
	if(cur==NULL)return 1;
	if(reverseRecursivePrintable(root, cur->next, cur))*root = cur;
	cur->next = prev;
	return 0;
	}

int main(){
	int n,i,ele;
	printf("Enter how many many nodes to be created : ");
	scanf("%d",&n);
	node *root=new node(),*current;
	root=NULL;
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
	printf("\nPress \n1 for Non Recursive Reverse \n2 for Recursive Reverse no Output \n3 for Recursive Reverse with Output\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1 : reverseNonRecursive(root);
			printf("\n");
			break;
		case 2 : reverseRecursive(root);
			break;
		case 3 : reverseRecursivePrintable(&root,root,NULL);
			printList(root);
			break;
		default : printf("Invalid choice");
	}
	die(&root);
	printf("\n\n**********************************THE END**********************************");
	return 0;
	}
