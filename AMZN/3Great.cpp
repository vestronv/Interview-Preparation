/*
The hiring team of Google aims to find 3 candidates who are great collectively. Each candidate has 
* his or her ability expressed as an integer. 3 candidate are great collectively if product of 
* their abilities is maximum. Find the maximum collective ability from the given pool of candidates.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int i,n;
		cin>>n;
		int arr[n];
		for(i=0; i<n; i++)cin>>arr[i];
		sort(arr,arr+n);
		cout<<max(arr[n-1]*arr[n-2]*arr[n-3] , 
		arr[0]*arr[1]*arr[n-1]);
		cout<<endl;
		}
	return 0;
	}
