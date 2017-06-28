/*
Given a pattern as below and an integer n your task is to decode it and print nth row of it. The pattern follows as :
1
11
21
1211
111221
*/
#include <bits/stdc++.h>
using namespace std;

string ans[21];

string to_string(int num){
	std::ostringstream ss;
	ss << num;
	return ss.str();
	}
void pre(){
	ans[1]="1";
	ans[2]="11";
	for(int i=3; i<21; i++){
		int len = ans[i-1].length(),k=0,p=0;
		string cur=""+ans[i-1][0];
		while(p<len){
			cur=ans[i-1][p];
			int curr=0;
			while(cur[0]==ans[i-1][k] && k<len){
				k++;curr++;
				}
			ans[i]+=to_string(curr)+cur;	
			p=k;
			}
		}
	}

int main(){
	pre();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<ans[n]<<endl;
		}
	return 0;
	}
