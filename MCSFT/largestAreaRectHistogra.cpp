/**
Description : Largest rectangular area under histogram.
O(n^2) approach
**/
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int l, int r){
	if(l>r)return -1;
	//cout<<l<<" "<<r<<endl;
	if(l==r)return arr[l];
	//if(l+1==r)return max(max(arr[l],arr[r]),2*min(arr[l],arr[r]));
	int m,mini=999999;
	for(int i=l; i<=r; i++)if(arr[i]<mini){mini=arr[i];m=i;}
	if(m==r)return max( solve(arr,l,m-1), max(solve(arr,m,m), (r-l+1)*arr[m]) );
	else if(m==l)return max( solve(arr,l,l), max(solve(arr,l+1,r), (r-l+1)*arr[m]) );
	return max(solve(arr,l,m), max(solve(arr,m+1,r), (r-l+1)*arr[m]));
	}

int main(){
	int arr[]={6, 1, 5, 4, 5, 2, 6};
	int sz = sizeof(arr)/sizeof(arr[0]);
	cout<<"Max area : "<<solve(arr,0,sz-1);
	return 0;
	}
