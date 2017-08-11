/**
Description : Validate an IP address.
**/

#include <bits/stdc++.h>
using namespace std;

bool corDig(string str){
	int len = str.length();
	if(len<1 )return false;
	int mul = pow(10,len-1),num=0;
	for(int i=0; i<len; i++){
		int dig = str[i]-'0';
		num += dig*mul;
		mul/=10;
		if(num>255)return false;
		}
	if(num<0 || num>255)return false;
	return true;
	}

//1.1.1.1     255.255.255.255
bool validateIP(string ip){
	int len = ip.length();
	if(len<7 || len>15)return false;
	string blk="";
	int i=0,lim=0;
	while(i<len){
		if(ip[i]!='.' && (ip[i]>'9' || ip[i]<'0'))return false;
		if(ip[i]=='.'){
			lim++;
			if(lim>3)return false;
			if(!corDig(blk))return false;
			blk="";
			i++;
			continue;;
			}
		blk+=ip[i];
		i++;
		}
	//parseDig()
	if(lim!=3)return false;
	if(ip[len-1]>'9' || ip[len-1]<'0')return false;
	return true;
	}

int main(){
	string ip;
	cin>>ip;
	if(validateIP(ip)){
		cout<<"Yes, a valid IP.\n\n";
		cout<<"                          /// "<<endl;
		cout<<"                        /// "<<endl;
		cout<<"                      /// "<<endl;
		cout<<"                    /// "<<endl;
		cout<<" \\\\\\              /// "<<endl;
		cout<<"  \\\\\\           /// "<<endl;
		cout<<"   \\\\\\        /// "<<endl;
		cout<<"    \\\\\\     /// "<<endl;
		cout<<"     \\\\\\__/// "<<endl;
		}
	else{
		cout<<"No, not a valid IP.\n\n";
		cout<<" \\\\\\                 /// "<<endl;
		cout<<"   \\\\\\             /// "<<endl;
		cout<<"     \\\\\\         /// "<<endl;
		cout<<"       \\\\\\     /// "<<endl;
		cout<<"         \\\\\\_/// "<<endl;
		cout<<"         /// \\\\\\ "<<endl;
		cout<<"       ///     \\\\\\ "<<endl;
		cout<<"     ///         \\\\\\ "<<endl;
		cout<<"   ///             \\\\\\ "<<endl;
		cout<<" ///                 \\\\\\ "<<endl;
		}
	return 0;
	}
