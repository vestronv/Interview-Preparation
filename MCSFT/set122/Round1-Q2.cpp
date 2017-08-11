#include <bits/stdc++.h>
using namespace std;
int tree[] = {1,-1,2,-1,-1,-1,4};
void kar_de_kaam(int del){
	int i,sz = (sizeof(tree)/sizeof(tree[0]));
	for(i=sz-1; i>=0; i--){
		if(tree[i] == del)break;
		}
	if(i*2 < sz){//check leaf node..
		return ;//not leaf...
		}
	if(i!=-1){
		tree[i]=-1;
		int parI=i;
		while(parI){
			parI = (i-1)/2;
			if(tree[parI*2 + 1] == -1 && tree[parI*2 + 2] == -1){
				tree[parI]=-1;
				i = parI;
				}
			else break;
			}
		if(parI == 0 && tree[parI*2 + 1] == -1 && tree[parI*2 + 2] == -1){
			tree[parI]=-1;
			}
		}
	}
void printTree(){
	for(int i=0; i<(int)(sizeof(tree)/sizeof(tree[0])); i++){
		cout<<tree[i]<<" ";
		}
	cout<<endl;
	}
int main(){
	int del = 2;
	cout<<"Before => ";printTree();
	kar_de_kaam(del);
	cout<<"After  => ";printTree();
	return 0;
	}
