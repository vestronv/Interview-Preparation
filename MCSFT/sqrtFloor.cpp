/**
Description : Square root floored of an integer.
**/

#include <bits/stdc++.h>
using namespace std;

int sqrtFloor(int n){
	if(n==0 || n==1)return n;
	int l=1,r=n/2,mid=(l+r)/2,ret=mid;
	while(l<=r){
		mid = (l+r)/2;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(mid*mid == n)return mid;
		if(mid*mid < n){
			l = mid+1;
			ret=mid;//bcoz we doing floor....otherwise this will be in next else..if ceil.
			}
		else{
			r = mid-1;
			}
		}
	return ret;
	}

int main(){
	int n;
	cin>>n;
	cout<<"Square root is : "<<sqrtFloor(n);
	return 0;
	}
