/**
Description : Row with maximum number of 1's. Row is sorted.
**/
#include <bits/stdc++.h>
using namespace std;

int bs(int arr[], int sz){
	int l=0,r=sz-1,mid;
	while(l<r){
		mid = (l+r)/2;
		if(arr[mid]==1){
			r=mid;
			}
		else{
			l=mid+1;
			}
		}
	if(mid>0){
		if(arr[mid-1]==1)return mid - 1;
		if(mid<sz-1)if(arr[mid+1]==1)return mid+1;
		}
	return arr[mid]==1?mid:mid+1;
	}

int main(){
	int mat[4][4]={
		{0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 0}
		},i,sz=4,ans=0,idxx=0;
	for(i=0; i<sz; i++){
		int idx = bs(mat[i],sz);
		//cout<<idx;
		if(ans<sz-idx)idxx=i;
		ans = max(ans, sz-idx);
		}
	cout<<"Answer is : "<<ans<<" Index is : "<<idxx<<endl;
	//method 2 solution...
	ans = -1, idxx = 0;
	int j=-1;
	for(i=0; i<sz; i++)if(mat[0][i]){j=i;break;}
	if(j==-1)j=sz-1;
	for(i=1; i<sz; i++){
		while(j>=0 && mat[i][j]){
			j = j-1;
			if(j>=0 && mat[i][j])ans = max(ans, sz-j);
			idxx = i;
			}
		if(j==0)break;
		}
	cout<<"Answer is : "<<ans<<" index is : "<<idxx<<endl;
	return 0;
	}
