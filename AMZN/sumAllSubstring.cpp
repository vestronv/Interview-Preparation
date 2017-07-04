#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string n;
	    cin>>n;
	    int ans = 0;
	    for(int i=0; i<n.length(); i++){
	        int cur = n[i]-'0';
	        ans += cur;
	        for(int j=i+1; j<n.length(); j++){
	            cur = cur*10 + (n[j]-'0');
	            ans += cur;
	        }
	    }
	cout<<ans<<endl;
	    
	}
	return 0;
}
