#include <bits/stdc++.h>
using namespace std;
string str[11] = {"","","abc","","","","bcd","ef","","xyz",""};;
int bs(string srch){
	int l=0,r=10,mid,lim=10;
	while(l < r){
		mid = (l+r)/2;
		if(str[mid] == srch)return mid;
		if(l+1 == r){
			if(str[r] == srch)return r;
			if(str[l] == srch)return l;
			else{
				int k=l;
				while(k<lim && str[k]=="")k++;
				if(k<lim && str[k][0] < str[mid][0]){
					l = k;
					}
				else{
					k=l;
					while(k>=0 && str[k]=="")k--;
					r = (k>=0 ? k: 0);
					}
				}
			}
		else if(str[mid] != ""){
			if(str[mid][0] < srch[0]){
				r = mid;
				}
			else l = mid;
			}
		else{
			int k=l;
			while(k<lim && str[k]=="")k++;
			if(k < lim && str[k][0] < str[mid][0]){
				l = k;
				}
			else{
				k=l;
				while(k>=0 && str[k]=="")k--;
				r = (k>=0 ? k: 0);
				}
			}
		}
	return str[mid]==srch ? mid : -1;
	}
int main(){
	
	string srch = "abc";
	int idx = bs(srch);
	if(idx != -1){
		cout<<"Found at "<<idx;
		}
	else cout<<"Not Found.";
	return 0;
	}
