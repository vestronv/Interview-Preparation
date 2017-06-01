/**
Description : Largest sub square matrix that has all 1's in it.
**/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int mat[6][5]={
		{0, 1, 1, 0, 1}, 
        {1, 1, 0, 1, 0}, 
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
		},i,j;
	int dp[6][5],ans=-1;
	for(i=0; i<6; i++)for(j=0; j<5; j++){dp[i][j]=0;}
	for(i=0; i<5; i++)dp[0][i]=mat[0][i];
	for(j=0; j<6; j++)dp[j][0]=mat[j][0];
	for(i=1; i<6; i++){
		for(j=1; j<5; j++){
			if(mat[i][j]==0)dp[i][j]=0;
			else{
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				}
			ans = max(ans,dp[i][j]);
			}
		}
	//for(i=0; i<6; i++){for(j=0; j<5; j++){cout<<dp[i][j]<<" ";}cout<<endl;}
	cout<<"Answer is : "<<ans;
	return 0;
	}
