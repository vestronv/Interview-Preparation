#include <bits/stdc++.h>
using namespace std;
bool isAlpha(char ch){return (ch>='0' && ch<='9') ? 1 : 0;}
int main() {
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int i,len=str.length(),ans=0,cur=0;
        for(i=len-1; i>=0; ){
            if(isAlpha(str[i])){
                cur=0;
                int p=0;
                while(isAlpha(str[i])){
                    cur += pow(10,p)*(str[i]-'0');
                    i--;p++;
                    if(i==-1)break;
                }
            }
            else {i--;continue;}
            if(cur>ans)ans = cur;
        }
        cout<<ans<<endl;
    }
	return 0;
}
