#include <bits/stdc++.h>
using namespace std;
int dp[900005];
int solve(int cur){
    if(cur<0)return 0;
    if(cur==0)return 0;
    if(dp[cur]!=-1){return dp[cur];}
    if(cur&1)return dp[cur] = 1+ solve(cur-1);
    return dp[cur] = 1+ solve(cur/2);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    memset(dp,-1,sizeof dp);
	    int n;
	    cin>>n;
	   cout<<(solve(n))<<endl;
	}
	return 0;
}
