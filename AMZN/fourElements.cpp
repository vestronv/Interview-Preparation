/*
Given an array of integers, find a combination of four elements in the array whose sum is equal to a given 
value X.
*/
#include <bits/stdc++.h>
using namespace std;

int arr[105];

vector<pair<int, pair<int,int> > >all(int st, int en){
	vector<pair<int, pair<int,int> > >ans;
	if(st>en)return ans;
	int i,j;
	for(i=st;i<=en;i++){
		for(j=i+1;j<=en;j++){
			ans.push_back(make_pair(arr[i]+arr[j],make_pair(i,j) ) );
			}
		}
	return ans;
	}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i,k;
		cin>>n;
		for(i=0;i<n;i++)cin>>arr[i];
		cin>>k;
		if(n<4){
		    cout<<0<<endl;continue;
		}
		vector<pair<int, pair<int,int> > >v1 = all(0,n-1);
		vector<pair<int, pair<int,int> > >::iterator vit1,vit2;
		map<int,vector<pair<int,int> > >m;
		map<int,int>mm;
		for(vit1=v1.begin();vit1!=v1.end();vit1++){
		    m[(*vit1).first].push_back((*vit1).second);
		    mm[(*vit1).first]=1;
		}
		//i know i can improve this... but i wouldn;t
		int flag=0;
		for(int i=0; i<n;i++){
		    for(int j=i+1;j<n;j++){
		        if(mm[k - arr[i]-arr[j] ]==1){
					for(vector<pair<int,int> >::iterator vp=m[k-arr[i]-arr[j] ].begin(); vp!=m[k-arr[i]-arr[j] ].end(); vp++){
						pair<int,int>pp=*vp;
						int x,y;
						x=pp.first;y=pp.second;
						if(i!=x && i!=y && j!=x && j!=y){
							flag=1;break;
							}
						}	            
					}
				}if(flag)break;
			}
		cout<<flag<<endl;
		}
	return 0;
	}
