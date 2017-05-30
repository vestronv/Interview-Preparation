/**
 * Description : Largest sum contiguous array.
**/
#include <bits/stdc++.h>
using namespace std;

int special(int arr[], int sz){
	int maxi = -9999,i;
	for(i=0; i<sz; i++){
		if(arr[i]>0)return -1;
		else maxi = max(maxi,arr[i]);
		}
	return maxi;
	}

int main(){
	int arr[]={-2,-3},i,sz;
	sz = sizeof(arr)/sizeof(arr[0]);
	int p = special(arr,sz);
	if(p != -1){
		cout<<"Answer is : "<<p;
		return 0;
		}
	int max_till_now = arr[0], max_considering_all=0;
	for(i=1; i<sz; i++){
		max_considering_all = max_considering_all + arr[i];
		if(max_considering_all < 0)max_considering_all = 0;
		if(max_till_now < max_considering_all){
			max_till_now = max_considering_all;
			}
		}
	cout<<"Answer is : "<<max_till_now;
	return 0;
	}
