#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005],arr[1005][1005],n;
int dp_solution(int row, int col){
    if(dp[row][col]!=-1)return dp[row][col];
    if(row == n-1)return arr[row][col];
    int ans=0;
    for(int i=0; i<n; i++){
        if(col != i)
        ans = max (ans, dp_solution(row+1,i));
    }
    return dp[row][col] = (ans+arr[row][col]);
}
int recursive_solution(int row, int col){
    if(row==n-1)return arr[row][col];
    int curMax = 0;
    for(int curCol=0; curCol<n; curCol++){
        if(col != curCol)
        curMax = max(curMax, recursive_solution(row+1,curCol));
    }
    return curMax + arr[row][col];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    memset(dp,-1,sizeof dp);
	    int i,j;
	    cin>>n;
	    for(i=0;i<n;i++)for(j=0;j<n;j++)cin>>arr[i][j];
	    int ans=0;
	    for(i=0;i<n;i++){
	        ans = max (ans, dp_solution(0,i)) ;
	        //ans = max (ans, recursive_solution(0,i)) ;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
