/*
Directi organizes FNCS (Friday Night Chill Session) every once in a 
while (lots of FUN!). Directians comes and enjoy various events and then 
go out when they get tired and come back again when they are refreshed. 
For convinience, in/out of any person is recoreded. At the end of the 
day, The organizer wonders what the maximum number of persons was 
during the event.
*/
#include <bits/stdc++.h>
using namespace std;
#define N 1005
int dp[N];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i,s,e,ans=0;
		cin>>n;
		for(i=0; i<N; i++)dp[i]=0;
		for(i=0; i<n; i++){
			cin>>s>>e;
			dp[s]++;dp[e+1]--;
			}
		for(i=1; i<N; i++){
			dp[i] += dp[i-1];
			}
		for(i=0; i<N-1; i++){
			if(dp[i+1]>=dp[i])ans = max(ans, dp[i]);
			}
		cout<<ans<<endl;
		}
	return 0;
	}
