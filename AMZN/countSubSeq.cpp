#include <bits/stdc++.h>
using namespace std;
//aaaccbcccacbbcc
unsigned long long solve(string yo, int pos, long long a, long long b, long long c){
	if(pos>=(int)yo.length())return c;
	unsigned long long tmp=0LL;
	if(yo[pos]=='a')tmp+=solve(yo,pos+1,2*a+1,b,c);
	else if(yo[pos]=='b')tmp+=solve(yo,pos+1,a,2*b+a,c);
	else if(yo[pos]=='c')tmp+=solve(yo,pos+1,a,b,2*c+b);
	else tmp+=solve(yo,pos+1,0LL,0LL,0LL);
	return tmp;
	}

int main(){
	int t;
	cin>>t;
	while(t--){
		string yo;
		cin>>yo;
		unsigned long long ans=0LL;
		for(int i=0;i<(int)yo.length();i++)	
			if(yo[i]=='a'){
				ans+=solve(yo,i+1,1,0,0);
				break;
				}
		cout<<ans<<endl;
		}
	return 0;
	}
