/**
Description : Longest even length substring such that sum of left substring of that equal
* sum of right leftover part.
**/
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int sz){
	int ret = 0;
	for(int i=0; i<sz-1; i++){
		int l=i,r=i+1,ls=0,rs=0;
		while(l>=0 && r<sz){
			ls += arr[l];
			rs += arr[r];
			if(ls==rs)ret = (r-l+1)%2==0?max(ret,r-l+1):ret;//btw no check req here..r-l+1
			//is always even...
			l--;r++;
			}
		}
	return ret;
	}

//this is O(n^2)
int main(){
	int arr[]={1,2,3,1,2,3};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int mat[sz][sz],i,j,k;
	for(i=0; i<sz; i++)for(j=0; j<sz; j++)mat[i][j]=0;
	for(i=0; i<sz; i++){
		for(j=i; j<sz; j++){
			if(j==i)mat[i][j]=arr[i];
			else mat[i][j] = mat[i][j-1]+arr[j];
			}
		}
	int ans = 0;
	for(i=0; i<sz; i++){
		for(j=i; j<sz; j++){
			for(k=j+1; k<sz; k++){
				if(mat[i][j]<mat[j+1][k])break;
				if(mat[j+1][k] == mat[i][j] && ((k-i+1)%2)==0){
					ans = max(ans, k-i+1);
					}
				}
			}
		}
	cout<<"Ans = "<<ans;
	printf("\n\nDifferent method solution(consider all mid points and expand)\n");
	ans = solve(arr,sz);
	cout<<"Ans = "<<ans;
	return 0;
	}
