/**
Description : Given an array in which every element occurs thrice exept single that
* appears only once find that one that appears only once.
**/
#include <bits/stdc++.h>
using namespace std;

int main(){
	//handling only valid I/P
	int arr[] = {1,1,1,2,2,2,3,3,3,4,5,5,5,6,6,6,7,7,7,8,8,8};//not 0's or negatives...
	int sz = sizeof(arr)/sizeof(arr[0]),i;
	int bit[32]={0};
	for(i=0; i<sz; i++){
		int ele = arr[i],k=0;
		while(ele>0){
			if(ele%2){
				bit[k]++;
				}
			k++;ele/=2;
			}
		}
	int ans=0;
	for(i=0; i<32; i++){
		if(bit[i]%3){
			ans += pow(2,i);
			}
		}
	cout<<"Element is : "<<ans;
	return 0;
	}
