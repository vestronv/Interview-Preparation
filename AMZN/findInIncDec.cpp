    #include <bits/stdc++.h>
    using namespace std;
    int peak(int arr[], int sz){
    	int mid,l=0,r=sz-1;
    	while(l < r){
    		mid = (l+r)/2;
    		//cout<<mid<<" "<<l<<" "<<r<<endl;
    		if(l+1 == r){
    			if(arr[l] > arr[r]){
    				mid = l;
    			}
    			else mid = r;
    		}
    		if(mid > 0 && arr[mid] > arr[mid-1]){
    			if(mid < sz-1 && arr[mid] > arr[mid+1])
    			return mid;
    		}
    		if(mid > 0 && arr[mid] > arr[mid-1]){
    			l = mid;
    		}
    		if(mid < sz-1 && arr[mid] > arr[mid+1]){
    			r = mid;
    		}
    	}
    	return mid;
    	}
    int bs(int arr[], int sz, int num){
    	int idx = peak(arr,sz);
    	int mid,l=0,r=idx;
    	while(l < r){
    		mid = (l+r)/2;
    		if(arr[mid]==num){
    			return mid;
    		}
    		if(l+1 == r){
    			if(arr[r] == num)return r;
    			if(arr[l] == num)return l;
    			else{l = l+1;continue;}
    		}
    		if(num < arr[mid]){
    			r = mid;
    		}
    		else if(num > arr[mid]){
    			l = mid;
    		}
    	}
    	if(arr[mid] == num)return mid;
    	//search other half
    	l = idx+1; r = sz - 1;
    	if(l >= sz)return arr[mid] == num ? mid : -1;
    	while(l < r){//cout<<"hi";
    		mid = (l+r)/2;
    		if(arr[mid]==num){
    			return mid;
    		}
    		//cout<<mid<<" "<<l<<" "<<r<<endl;
    		if(l+1 == r){
    			if(arr[r] == num)return r;
    			if(arr[l] == num)return l;
    			else{l = l+1;continue;}
    		}
    		if(num < arr[mid]){
    			l = mid;
    		}
    		else if(num > arr[mid]){
    			r = mid;
    		}
    	}
    	return arr[mid] == num ? mid : -1;
    	}
    int main() {
    	// your code goes here
    	int arr[] = {1,3,5,7,9,8,6,2};
    	int sz = sizeof(arr)/sizeof(arr[0]);
    	int num = 1;
    	int idx = bs(arr,sz,num);
    	if(idx != -1)cout<<"Found at(0-indexing) ->"<<idx;
    	else cout<<"Not Found.";
    	return 0;
    }
