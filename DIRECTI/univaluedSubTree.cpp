#include <bits/stdc++.h>
using namespace std;
#define N 1000
int current=1,st[N],en[N],vis[N],val[N];
map<int,vector<int> >g;
void dfs(int node){
	val[current]=node;
	st[node]=current++;
	vis[node]=1;
	for(vector<int>::iterator vit=g[node].begin(); vit!=g[node].end(); vit++){
		if(!vis[*vit]){
			dfs(*vit);
			}
		}
	vis[node]=0;
	en[node]=current++;
	}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i,u,v;
		cin>>n;
		for(i=0; i<n-1; i++){
			cin>>u>>v;
			g[u].push_back(v);
			}
		dfs(1);
		for(i=2; i<N; i++){
			val[i] += val[i-1];
			if(i<30)cout<<val[i]<<" ";
			}
		int ans=0;
		for(map<int, vector<int> >::iterator mit = g.begin(); mit!=g.end(); mit++){
			int nn = (*mit).first;
			int valu = en[nn]-st[nn];
			if(valu==0)ans++;
			else if(valu/st[nn] == (en[nn]-st[nn]))ans++;
			}
		cout<<ans<<endl;
		}
	return 0;
	}
