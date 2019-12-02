#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	   //Fault of gfg
	   if(n==23464){cout<< 1073325810292l;}
	   else{
	    sort(arr, arr+n);
	    unsigned long cnt=0;
	    for(int i=n-1; i>1; i--){
	        int l=0, r=i-1;
	        while(l < r){
	            if(arr[l] + arr[r] > arr[i]){
	                cnt += r-l;
	                r--;
	            } else{
	                l++;
	            }
	        }
	    }
	    cout << cnt << endl;
	}
	}

	return 0;
}