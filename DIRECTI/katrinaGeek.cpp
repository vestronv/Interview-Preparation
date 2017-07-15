#include <bits/stdc++.h>
using namespace std;
int solve(int mat[64][64], int n, int m){
	int dp[n+1][m+1],i,j;
	for(i=0; i<=n; i++){
		for(j=0; j<=m; j++)dp[i][j]=0;
		}
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			if(i+mat[i][j] <= n){
				if(dp[i+mat[i][j]][j]==0)dp[i+mat[i][j]][j]=dp[i][j]+1;
				else dp[i+mat[i][j]][j] = min(dp[i+mat[i][j]][j], 1+dp[i][j]);
				}
			if(j+mat[i][j] <= m){
				if(dp[i][j+mat[i][j]]==0)dp[i][j+mat[i][j]]=dp[i][j]+1;
				else dp[i][j+mat[i][j]] = min(dp[i][j+mat[i][j]], 1+dp[i][j]);
				}
			}
		}
	//for(i=1; i<=n; i++){
	//	for(j=1; j<=m; j++)cout<<dp[i][j]<<" ";
	//	cout<<endl;
	//	}
	return dp[n][m]==0?0:dp[n][m]+1;
	}
int main(){
	int t;
	cin>>t;
	while(t--){
		int i,j,ans,n,m;
		cin>>n>>m;
		int mat[64][64];
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				cin>>mat[i][j];
				}
			}
		ans = solve(mat,n,m);
		cout<<ans<<endl;
		}
	return 0;
	}
