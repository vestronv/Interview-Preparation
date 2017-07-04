#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s1,s2;
	    cin>>s1>>s2;
	    int i,l1=s1.length(),l2=s2.length();
	    int freq[26],ans[26];
	    memset(freq,0,sizeof freq);
	    memset(ans,0,sizeof ans);
	    
	    for(i=0; i<l1; i++){
	        freq[s1[i]-'a']=1;
	    }
	    for(i=0; i<l2; i++){
	        if(freq[s2[i]-'a']==0){
	            ans[s2[i]-'a']=1;
	        }
	    }
	    memset(freq,0,sizeof freq);
	    for(i=0; i<l2; i++){
	        freq[s2[i]-'a']=1;
	    }
	    for(i=0; i<l1; i++){
	        if(freq[s1[i]-'a']==0){
	            ans[s1[i]-'a']=1;
	        }
	    }
	for(i=0; i<26; i++){
	    if(ans[i])cout<<char(i+'a');
	}
	    cout<<endl;
	}
	return 0;
}
