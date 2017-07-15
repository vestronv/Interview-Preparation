/*
Given two strings s1 and s2 of same length, you can swap s1[i] with s2[i] finally
you want to minimize max(disChar(s1),disChar(s2))
*/
#include <bits/stdc++.h>
using namespace std;
int c1[26]={0},c2[26]={0},n;
string s1,s2;
int solve(int idx){
	int i;
	if(idx==n){
		int p=0,q=0;
		for(i=0; i<26; i++)if(c1[i])p++;
		for(i=0; i<26; i++)if(c2[i])q++;
		return max(p,q);
		}
	c1[s1[idx]-'a']++;
	c2[s2[idx]-'a']++;
	int ans = solve(idx+1);
	c1[s1[idx]-'a']--;
	c2[s2[idx]-'a']--;
	
	c1[s2[idx]-'a']++;
	c2[s1[idx]-'a']++;
	ans = min(ans, solve(idx+1));
	c1[s2[idx]-'a']--;
	c2[s1[idx]-'a']--;
	return ans;
	}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s1>>s2;
		memset(c1, 0, sizeof c1);
		memset(c2, 0, sizeof c2);
		n = (int)s1.length();
		cout<<solve(0)<<endl;
		}
	return 0;
	}
