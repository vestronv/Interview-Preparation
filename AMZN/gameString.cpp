/*
Given a string of lowercase alphabets and a number k, the task is to print the minimum value of the string 
after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each 
distinct character.
Example:
Input : str = abccc, K = 1
Output : 6
We remove c to get the value as 11 + 11 + 22
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,k;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		cin>>k;
		//if(k>=26){cout<<"0\n";continue;}
		int freq[26];
		memset(freq, 0, sizeof freq);
		for(int i=0; i<(int)str.length(); i++){
			freq[str[i]-'a']++;
			}
		sort(freq, freq+26, greater<int>());
		int ans=0;
		for(int i=0; i<k; i++){
			int j=0;
			while(j<25 && freq[j]>0 && freq[j]==freq[j+1]){j++;}
			if(j==25){
				freq[j]-=1;
				}
			else{freq[j]-=1;}
			}
		for(int i=0; i<26; i++){
			ans += freq[i]*freq[i];
			}
		cout<<ans<<endl;
		}
	return 0;
	}
