/**
Description : Sort array such that all odd elements are first and in descending order
* and all even elements are at last and in ascending order.
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[]={1,2,3,4,5,6,7,7,6,5,4,3,2,3,4,5,6,7};
	int sz = sizeof(arr)/sizeof(arr[0]),i;
	int l=0,r=sz-1,upto=0;
	while(l<r){
		while(arr[l]%2!=0 && l<r){
			l++;upto++;
			}
		while(arr[r]%2==0 && l<r){
			r--;
			}
		if(l<r)swap(arr[l],arr[r]);
		}
	sort(arr,arr+upto,greater<int>());
	sort(arr+upto,arr+sz);
	printf("Sorted array in descending and ascending order is : ");
	for(i=0; i<sz; i++){
		printf(" %d ",arr[i]);
		}
	return 0;
	}
