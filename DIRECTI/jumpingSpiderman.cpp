/*
Consider NewYork city which has grid like structure of houses. 
You are provided the city map in the form of a matrix. Each cell 
represents a building. From each building you can go to adjacent four 
buildings in four directions : east, west, north, south. Spiderman 
wants to rescue a victim which is on some building. You will be provided 
with the location of victim and spiderman is situated at (1,1) building. 
But, there is a condition that spiderman can not jump between buildings 
if the difference in their heights is greater than some particular 
value. Find a way for spiderman to reach the victim by crossing the 
minimum number of buildings.

Input
Input contains multiple test cases. First Line is a integer T, 
representing the number of test cases to follow.

First line of each test case has 4 numbers – M, N, X, Y, D. Here MxN is 
the dimension of the city grid. (X,Y) is location of victim.

This is followed by M lines. Each line consist of N space separated 
positive integers corresponding to building heights. D is the maximum 
difference between heights of buildings that spiderman can cross.
Output
One line for each test case containing a single integer, denoting the 
minimum number of buildings spiderman needs to cross. Return -1 if its 
not not possible.
*/
#include <bits/stdc++.h>
using namespace std;
#define inf 8888
int arr[64][64],vis[64][64],n,m,d,ans,p;
void solve(int curx, int cury, int fx, int fy, int cur){
	if(vis[curx][cury])return;
	if(curx==fx && cury==fy){ans = min(ans,cur);return;}
	vis[curx][cury]=1;
	if(curx+1<=n && abs(arr[curx+1][cury]-arr[curx][cury]) <= d && !vis[curx+1][cury]){
		solve(curx+1, cury, fx, fy, cur+1);
		}
	if(curx-1>=1 && abs(arr[curx-1][cury]-arr[curx][cury]) <= d && !vis[curx-1][cury]){
		solve(curx-1, cury, fx, fy, cur+1);
		}
	if(cury+1<=m && abs(arr[curx][cury+1]-arr[curx][cury]) <= d && !vis[curx][cury+1]){
		solve(curx, cury+1, fx, fy, cur+1);
		}
	if(cury-1>=1 && abs(arr[curx][cury-1]-arr[curx][cury]) <= d && !vis[curx][cury-1]){
		solve(curx, cury-1, fx, fy, cur+1);
		}
	vis[curx][cury]=0;
	return;
	}
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y,i,j;
		//clean
		ans=inf;
		
		cin>>n>>m>>x>>y>>d;
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				cin>>arr[i][j];
				}
			}
			
		solve(1, 1, x, y, 1);
		if(ans==inf)ans=-1;
		cout<<ans-2<<endl;
		}
	return 0;
	}
