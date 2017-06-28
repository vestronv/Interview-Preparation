#include <bits/stdc++.h>
using namespace std;

int dist(int x1, int y1, int x2, int y2){
	return abs(x1-x2) * abs(x1-x2) + abs(y1-y2) * abs(y1-y2);
	}

int main(){
	int t,x1,x2,x3,x4,y1,y2,y3,y4;
	cin>>t;
	while(t--){
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		int diag=0,side=0;
		int a,b,c;
		a=dist(x1,y1,x2,y2);
		b=dist(x1,y1,x3,y3);
		c=dist(x1,y1,x4,y4);
		if(a==b&& a!=c){
			side=a;diag=c;
			}
		else if(b==c && b!=a){
			side=b;diag=a;	
			}
		else if(a==c && a!=b){
			side=c;diag=b;
			}
		else {cout<<"No\n";continue;}
		if(side==0 || diag==0){cout<<"No\n";continue;}
		///////////////////////////////////////////////////////////
		int flag=0;
		a=dist(x2,y2,x1,y1);
		b=dist(x2,y2,x3,y3);
		c=dist(x2,y2,x4,y4);
		if(a==b&& a!=c){
			if(side!=a && diag!=c)flag=1;
			}
		else if(b==c && b!=a){
			if(side!=b && diag!=a)flag=1;	
			}
		else if(a==c && a!=b){
			if(side!=c && diag!=b)flag=1;
			}
		else {cout<<"No\n";continue;}
		if(flag){cout<<"No\n";continue;}
		////////////////////////////////////////////////////////////////
		a=dist(x3,y3,x2,y2);
		b=dist(x3,y3,x1,y1);
		c=dist(x3,y3,x4,y4);
		if(a==b&& a!=c){
			if(side!=a && diag!=c)flag=1;
			}
		else if(b==c && b!=a){
			if(side!=b && diag!=a)flag=1;
			}
		else if(a==c && a!=b){
			if(side!=c && diag!=b)flag=1;
			}
		else {cout<<"No\n";continue;}
		if(flag){cout<<"No\n";continue;}
		/////////////////////////////////////////////////////////////////////
		a=dist(x4,y4,x2,y2);
		b=dist(x4,y4,x3,y3);
		c=dist(x4,y4,x1,y1);
		if(a==b&& a!=c){
			if(side!=a && diag!=c)flag=1;
			}
		else if(b==c && b!=a){
			if(side!=b && diag!=a)flag=1;
			}
		else if(a==c && a!=b){
			if(side!=c && diag!=b)flag=1;
			}
		else {cout<<"No\n";continue;}
		if(flag){cout<<"No\n";continue;}
		/////////////////////////////////////////////////////////////////////////////
		cout<<"Yes\n";
		}
	return 0;
	}
