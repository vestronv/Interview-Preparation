#include <bits/stdc++.h>
using namespace std;
priority_queue<int>left_side;
priority_queue<int, vector<int>, greater<int> >right_side;
double median = 0.0;
double find_median(int x){
	if(left_side.size() > right_side.size()){
		int a = left_side.top();
		if(median > (double)x){
			left_side.pop();
			left_side.push(x);
			right_side.push(a);
			}
		else{
			right_side.push(x);
			}
		median = ((double)left_side.top() + 
			(double)right_side.top())/2.0;
		}
	else if(left_side.size() == right_side.size()){
		if(median > x){
			left_side.push(x);
			median = (double)left_side.top();
			}
		else{
			right_side.push(x);
			median = (double)right_side.top();
			}
		}
	else{
		int a = right_side.top();
		if(median < (double)x){
			left_side.push(a);
			right_side.pop();
			right_side.push(x);
			}
		else{
			left_side.push(x);
			}
		median = ((double)left_side.top() + 
			(double)right_side.top())/2.0;
		}
	return median;
	}
int main(){
	int arr[] = {5,15,10,20,3};
	int i,n = sizeof(arr)/sizeof(arr[0]);
	median = 0.0;
	for(i=0; i<n; i++){
		median = find_median(arr[i]);
		cout<<median<<" ";
		}
	return 0;
	}
