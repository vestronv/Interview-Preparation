#include <bits/stdc++.h>
using namespace std;

int N = 105,top=0,sz=0,smalFreq=-1,smalNum=-1;
int harr[N],freq[N];

int get_second( pair<string, int> i ){ return i.second; }

int main(){
	int t,i,ele;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		sz=k;
		map<int,int>m;
		for(i=0; i<n; i++){
			cin>>ele;
			freq[ele]++;
			m[ele]++;
			vector<int> v(m.size());
			transform(m.begin(), m.end(),v.begin(),get_second);
			if(i<k){
				for(map<int,int>::iterator mit=m.)
				}
			if(freq[ele]>=smalFreq){
				if(freq[ele]>smalFreq){//karna hi padega insert
					//inesrt here
					
					smalFreq = findSmalFreq();
					smalNum = findSmalNum();
					}
				else{
					if(ele < smalNum){
						//insert here
						
						smalNum = findSmalNum();
						}
					}
				}
			}
		cout<<endl;
		}
	return 0;
	}

/*
#include <bits/stdc++.h>
using namespace std;

int N = 105,top=0,sz=0,smalFreq=-1,smalNum=-1;
int harr[N],freq[N];

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b =temp;
	}
inline int parent(i){return (i-1)/2;}
inline int left(i){return 2*i+1;}
inline int right(i){return 2*i+2;}

void heapInsert(int ele){
	if(top==0){
		harr[top++]=ele;
		return;
		}
	++top;
	int idx = top-1;
	harr[idx] = ele;
	while(idx!=0 && harr[parent(idx)] > harr[idx]){
		swap(&harr[idx], &harr[parent(idx)]);
		idx = parent(idx);
		}
	}

int main(){
	int t,i,ele;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		sz=k;
		for(i=0; i<n; i++){
			cin>>ele;
			freq[ele]++;
			if(freq[ele]>=smalFreq){
				if(freq[ele]>smalFreq){//karna hi padega insert
					//inesrt here
					
					smalFreq = findSmalFreq();
					smalNum = findSmalNum();
					}
				else{
					if(ele < smalNum){
						//insert here
						
						smalNum = findSmalNum();
						}
					}
				}
			//heapInsert(ele);
			//vector<int> ans = findMax();
			//for(vector<int>::iterator vit = ans.begin(); vit!=ans.end(); vit++){
			//	cout<<*vit<<" ";
			//	}
			}
		cout<<endl;
		}
	return 0;
	}
*/
