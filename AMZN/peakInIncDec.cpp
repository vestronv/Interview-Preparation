#include <bits/stdc++.h>
using namespace std;
int peak(int arr[], int sz){
	int mid,l=0,r=sz-1;
	while(l < r){
		mid = (l+r)/2;
		//cout<<mid<<" "<<l<<" "<<r<<endl;
		if(l+1 == r){
			if(arr[l] > arr[r]){
				mid = l;
			}
			else mid = r;
		}
		if(mid > 0 && arr[mid] > arr[mid-1]){
			if(mid < sz-1 && arr[mid] > arr[mid+1])
			return mid;
		}
		if(mid > 0 && arr[mid] > arr[mid-1]){
			l = mid;
		}
		if(mid < sz-1 && arr[mid] > arr[mid+1]){
			r = mid;
		}
	}
	return mid;
	}
int main() {
	// your code goes here
	int arr[] = {1, 3, 50, 10, 9, 7, 6};
	int sz = sizeof(arr)/sizeof(arr[0]);
	//int num = 8;
	int idx = peak(arr,sz);
	cout<<"Index = "<<idx<<", Element = "<<arr[idx];
	return 0;
}
