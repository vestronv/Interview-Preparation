#include <iostream>
using namespace std;
//check if binary of a nmbr is palindrome without extra space
int findNumBits(int n){
	int ans = 0;
	while(n){
		n = n>>1;
		ans++;
	}
	return ans;
	}
int main() {
	// your code goes here
	int n = 45;
	int num_bits = findNumBits(n);
	cout<<"Num of bits = "<<num_bits<<endl;
	if(num_bits & 1){//odd
		int a=0,b=0,c=0;
		while(n){
			if(c<(num_bits/2)){
				a = a << 1;
				a = a | (n&1);
			}else{
				break;
			}
			n>>=1;
			c++;
		}
		n>>=1;
		//cout<<"n="<<n<<" a="<<a<<endl;
		if(n == a){
			cout<<"Yes";
		}
		else{
			cout<<"No";
		}
	}
	else{
		int a=0,b=0,c=0;
		while(n){
			if(c<(num_bits/2)){
				a = a << 1;
				a = a | (n&1);
			}else{
				break;
			}
			n>>=1;
			c++;
		}
		if(n == a){
			cout<<"Yes";
		}
		else{
			cout<<"No";
		}
	}
	return 0;
}
