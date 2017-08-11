#include <bits/stdc++.h>
using namespace std;
void compress(int arr[], int sz){
	vector<int>ans;
	int zero=0,sum=0;
	int tmp=0;
	while(arr[tmp]==0){
		zero++;
		tmp++;
		}
	for(int i=0; i<zero/2; i++)ans.push_back(0);
	zero=0;
	while(arr[tmp]){
		sum += arr[tmp];
		tmp++;
		}
	ans.push_back(sum);
	sum=0;
	for(int i=tmp; i<sz; ){
		if(i+1 < sz && arr[i]==0 && arr[i+1]==0){
			ans.push_back(0);
			i+=2;
			}
		else if(arr[i]==0){
			if(zero%2){
				ans.push_back(sum);
				sum=0;
				}
			zero++;
			i++;
			}
		else{sum += arr[i];i++;}
		}
	if(sum)ans.push_back(sum);
	for(vector<int>::iterator vit = ans.begin(); vit!=ans.end(); vit++){
		cout<<(*vit)<<" ";
		}
	}
int main(){
	int arr[] = {0,0,0,7,0,4,5,6,0,1,1};
	int sz = (int)(sizeof(arr)/sizeof(arr[0]));
	compress(arr,sz);
	return 0;
	}
