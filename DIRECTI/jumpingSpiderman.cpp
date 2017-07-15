#include <bits/stdc++.h>
using namespace std;
int arr[64][64],dp[64][64];
int solve(int curx, int cury, int fx, int fy){
	if(curx==fx && cury==fy){return 1;}
	if(curx+1<=n && abs(arr[curx+1][cury]-arr[curx][cury]) <= d){
		if(dp[curx+1][cury]==0)dp[curx+1][cury]=dp[curx][cury]+1;
		else dp[curx+1][cury] = 
			min(dp[curx+1][cury], dp[curx][cury]+solve(curx+1, cury, fx, fy));
		}
	}
int main(){
	int t;
	cin>>t;
	while(t--){
		//clean
		for(i=0; i<64; i++)for(j=0; j<64; j++){dp[i][j]=arr[i][j]=0;}
		
		int n,m,x,y,d,i,j;
		cin>>n>>m>>x>>y>>d;
		int arr[n+1][m+1],dp[n+1][m+1];
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				cin>>arr[i][j];
				dp[i][j]=0;
				}
			}
		solve(1,1,x,y);
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				if(dp[i][j]==0 && (i!=1 || j!=1))continue;
				if(i+1 <= n && abs(arr[i+1][j]-arr[i][j]) <= d){
					if(dp[i+1][j]==0)
						dp[i+1][j] = dp[i][j]+1;
					else
						dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
					}
				if(i-1 >= 1 && abs(arr[i-1][j]-arr[i][j]) <= d){
					if(dp[i-1][j]==0)
						dp[i-1][j] = dp[i][j]+1;
					else
						dp[i-1][j] = min(dp[i-1][j], dp[i][j]+1);
					}
				if(j+1 <= m && abs(arr[i][j+1]-arr[i][j]) <= d){
					if(dp[i][j+1]==0)
						dp[i][j+1] = dp[i][j]+1;
					else
						dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
					}
				if(j-1 >= 1 && abs(arr[i][j-1]-arr[i][j]) <= d){
					if(dp[i][j-1]==0)
						dp[i][j-1] = dp[i][j]+1;
					else
						dp[i][j-1] = min(dp[i][j-1], dp[i][j]+1);
					}
				}
			}
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				cout<<dp[i][j]<<" ";
				}
			cout<<endl;
			}
		if(dp[x][y]>0)
			dp[x][y]+=1;
		else dp[x][y]=-1;
		cout<<dp[x][y]<<endl;
		}
	return 0;
	}
