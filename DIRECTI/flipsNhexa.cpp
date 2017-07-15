#include <bits/stdc++.h>
using namespace std;
#define N 10000
struct node{
	int num0,num1;
	}segT[4*N+500];
int a[N+50];
void build(int st=1, int en=N, int idx=1){
	if(st==en){
		segT[idx].num0=1;
		segT[idx].num1=0;
		return ;
		}
	int mid = (st+en)>>1;
	build(st, mid, 2*idx);
	build(mid+1, en, 2*idx+1);
	segT[idx].num0 = segT[2*idx].num0 + segT[2*idx+1].num0;
	segT[idx].num1 = segT[2*idx].num1 + segT[2*idx+1].num1;
	}
void update(int st, int en, int idx, int l, int r){
	if(st>en)return ;
	if(en<l || st>r)return;
	if(l<=st && r>=en){
		int temp = segT[idx].num0;
		segT[idx].num0 = segT[idx].num1;
		segT[idx].num1 = temp;
		return ;
		}
	int mid = (st+en)>>1;
	update(st, mid, 2*idx, l, r);
	update(mid+1, en, 2*idx+1, l, r);
	segT[idx].num0 = segT[2*idx].num0 + segT[2*idx+1].num0;
	segT[idx].num1 = segT[2*idx].num1 + segT[2*idx+1].num1;
	}
int main(){
	//build();
	int t;
	cin>>t;
	while(t--){
		int n,i;
		cin>>n;
		for(i=0; i<n; i++){
			int x,y;
			cin>>x>>y;
			//update(1,N,1,x,y);
			a[x]++;a[y+1]--;
			}
		for(i=1; i<=N; i++)a[i]+=a[i-1];
		for(i=1; i<=N; i++)a[i]=a[i]&1;
		i=1;
		int s=0,l=0,h[16];
		memset(h,0,sizeof h);
		while(i<=N){
			s += a[i]<<(3-l);
			l++;
			i++;
			if(l==4){
				h[s]++;
				s=0;l=0;
				}
			}
		for(i=0; i<16; i++)cout<<h[i]<<" ";
		//cout<<segT[1].num0<<" "<<segT[1].num1<<endl;
		}
	return 0;
	}
