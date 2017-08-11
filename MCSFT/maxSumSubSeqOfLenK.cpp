#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,i;
		cin>>n>>k;
		int arr[n];
		for(i=0; i<n; i++)cin>>arr[i];
		int ans=0;
		priority_queue<int, vector<int>, greater<int> >pq;
		for(i=0; i<k; i++){
			pq.push(arr[i]);
			}
		for(i=k; i<n; i++){
			int p = pq.top();
			if(p < arr[i]){
				pq.pop();
				pq.push(arr[i]);
				}
			}
		while(!pq.empty()){
			int p = pq.top();
			pq.pop();
			ans += (p);
			}
		cout<<ans<<endl;
		}
	}
