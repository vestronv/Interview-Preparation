/*
Consider two stairways, A and B, which are parallel to each other. 
Both stairways, A and B, have N steps each where A[i], B[i] represent 
i-th step of A and B respectively.
Each step has some amount of penalty associated and if you use that 
step you will be penalized by the same amount. After taking few steps 
you will accumulate penalty of all of the steps you visited.
*/
/*
#include <bits/stdc++.h>
using namespace std;
#define inf 99999
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,p,i,j;
		cin>>n>>k>>p;
		int a[n+1],b[n+1];
		for(i=1; i<=n; i++)
		cin>>a[i];
		for(i=1; i<=n; i++)
		cin>>b[i];
		int dp[n+1][2];
		for(i=0; i<=n; i++)dp[i][0]=dp[i][1]=inf;
		dp[1][0] = a[1];
		dp[1][1] = b[1];
		for(i=1; i<=n; i++){
			for(j=i+1; j<=i+k && j<=n; j++){
				dp[j][0] = min(dp[j][0], min(dp[i][0]+a[j], p+dp[i][1]+a[j] ));
				dp[j][1] = min(dp[j][1], min(dp[i][1]+b[j], p+dp[i][0]+b[j] ));
			}
			}
		cout<<min(dp[n][0], dp[n][1])<<endl;
		}
	return 0;
	}
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
bool solve(int a, int b){
	//cout<<a<<" "<<b<<" ";
	//int p;
	//cin>>p;
	if(a < 1 || b < 1)return false;
	if(a==1 && b==1)return true;
	int i=2;
	while(i){
		if((a/(i*i)) >= 1 || (b/(i*i)) >= 1 ){
			if(((a % (i*i)) == 0 || (b % (i*i)) == 0 )){
				if(solve(a/(i*i), b/i) || solve(a/i, b/(i*i)))
					return true;
				}
			}
		else break;
		i++;
		}
	return false;
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		cin>>a>>b;
		if(solve(a,b))cout<<"Yes\n";
		else cout<<"No\n";
		}
	return 0;
	}
