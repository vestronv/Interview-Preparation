#include <bits/stdc++.h>
using namespace std;

map<int, map<int, map<int,map<int,int> > > >dpp;
int dp[1005][1005],arr[1005][1005];
int ans=-1,n,m;

int sum(int x1, int y1, int x2, int y2){
    return (dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1]);
}
int solve(int x1,int y1,int x2, int y2){
    if(x1>x2 || y1>y2 || x1>n || y1>m || x2<1 || y2<1)return 0;
    if(dpp[x1][y1][x2].find(y2)!=dpp[x1][y1][x2].end())
    return dpp[x1][y1][x2][y2];
    int tmp=0;
    if((tmp=sum(x1,y1,x2,y2))>ans){
        ans = tmp;
    }
    ans = max(ans, solve(x1+1,y1,x2,y2));
    ans = max(ans, solve(x1,y1+1,x2,y2));
    ans = max(ans, solve(x1,y1,x2-1,y2));
    ans = max(ans, solve(x1,y1,x2,y2-1));
    return dpp[x1][y1][x2][y2]=ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int i,j;
        dpp.clear();
        cin>>n>>m;
        ans=-1;
        for(i=0; i<=n; i++){
        for(j=0; j<=m; j++){
           arr[i][j]=0;dp[i][j]=0;
        }//cout<<endl;
    }
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++)cin>>arr[i][j];
        }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(i==1){
                dp[i][j]=dp[i][j-1]+arr[i][j];
                continue;
            }
            else if(j==1){
                dp[i][j]=dp[i-1][j]+arr[i][j];
                continue;
            }
            dp[i][j] = arr[i][j]+dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    
    
    solve(1,1,n,m); 
    cout<<ans<<endl;
    }
    return 0;
}
