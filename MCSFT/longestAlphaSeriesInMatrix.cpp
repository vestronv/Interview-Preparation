// C++ program to find the longest consecutive path
#include<bits/stdc++.h>
#define R 3
#define C 3
using namespace std;
int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};
int dp[R][C];
bool isvalid(int i, int j){
    if (i < 0 || j < 0 || i >= R || j >= C)
      return false;
    return true;
}
bool isadjacent(char prev, char curr){
    return ((curr - prev) == 1);
}
int getLenUtil(char mat[R][C], int i, int j, char prev){
	if(!isvalid(i,j) || !isadjacent(prev,mat[i][j]))return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int cur=0;
	for(int k=0; k<8; k++)
		cur = max(cur, 1+getLenUtil(mat,i+x[k],j+y[k],mat[i][j]));
	return dp[i][j]=cur;
}
int getLen(char mat[R][C], char s){
	memset(dp,-1,sizeof dp);
	int i,j,ans=0;
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(mat[i][j] == s){
				dp[i][j]=1;
				for(int k=0; k<8; k++){
					ans = max(ans,1+ getLenUtil(mat,i+x[k],j+y[k],s));
				}
			}
		}
	}
return ans;
}
 
// Driver program
int main() {
 
    char mat[R][C] = { {'a','c','d'},
                     { 'h','b','a'},
                     { 'i','g','f'}};
 
    cout << getLen(mat, 'a') << endl;
    cout << getLen(mat, 'e') << endl;
    cout << getLen(mat, 'b') << endl;
    cout << getLen(mat, 'f') << endl;
    return 0;
}
