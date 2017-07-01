#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		int i,len=str.length();
		map<int,string>freq;
		cin>>str;
		for(i=0; i<len; i++){int temp;cin>>temp;freq[temp]=""+str[i];}
		map<int,string>::iterator mit=freq.begin();
		vector<pair<string,vector<int> > >ans;
		while(freq.size()>1){
			int t1=(*mit).first;
			string s1=(*mit).second;
			freq.erase(mit++);
			int t2=(*mit).first;
			string s2=(*mit).second;
			freq.erase(mit++);
			freq[t1+t2]=s1+s2;
			vector<vector<int> >::iterator vit = find(ans.begin(), ans.end()s1);
			vit.push_back(0);
			vit = ans.find(s2);
			vit.push_back(1);
			}
		}
	return 0;
	}
