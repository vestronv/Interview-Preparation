/*
Given a string and a pattern, Replace all the continuous occurrence of pattern with a single 
* X in the string. For a clear view see the example below.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string str,pat;
		cin>>str>>pat;
		int i,l1=str.length(),l2=pat.length();
		if(l2>l1){cout<<str<<endl;continue;}
		string ans="",temp="";
		int j=0,pr=0;
		for(i=0; i<l1; ){
			if(str[i]==pat[j]){
				if(j==l2-1){ans+="X";j=0;i++;pr=i;temp="";}
				else {temp+=str[i];i++;j++;}
				}
			else if(j){j=0;
				while(pr<l1 && j<l2 && str[pr]==pat[j] ){
					ans+=str[pr];pr++;j++;
					}
				j=0;temp="";
				}
			else{temp="";ans+=str[i];i=pr+1;pr=i;j=0;}
			}
		string anss="";
		i=0;
		ans+=temp;
		while(i<(int)ans.length()){
			if(ans[i]!='X')anss+=ans[i++];
			else {anss+='X';
				while(ans[i]=='X' && i<(int)ans.length())i++;
				}
			}
		cout<<anss<<endl;
		}
	return 0;
	}
