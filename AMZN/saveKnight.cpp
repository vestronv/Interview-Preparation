/*
How many non-attacking knights K(n) can be placed on an n x n chessboard. 
Recall that a knight can attack another knight if their vertical distance 
* on the chessboard is 2 and their horizontal distance is 1, or if their 
* vertical distance is 1 and their horizontal distance is 2. Only one 
* knight may be placed on each square of the chessboard.
 * */
#include <bits/stdc++.h>
using namespace std;

inline int mysum(int n){return ((n)*(n));}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<3){
			cout<<n*n<<endl;
			continue;
			}
		if(n&1){
			cout<<mysum((n+1)/2)+mysum((n+1)/2 - 1);
			}
		else{
			cout<<2*(mysum((n+1)/2));
			}
		cout<<endl;
		}
	return 0;
	}
