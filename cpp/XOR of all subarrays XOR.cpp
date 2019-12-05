/*
You are given an array A[] of size N. Now, we call the value of an array the bit-wise XOR of all 
elements it contains. For example, the value of the array [1,2,3] = 1^2^3. Now, Your task is to 
find the bit-wise XOR of the values of all sub arrays of array A. 
*/
#include<iostream>
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int arr[MAX];

int getXoR(int n){
    if (n%2==0)
        return 0;
    int ans = 0;
    for (int i=0; i<n; i+=2)
            ans ^= arr[i];
    return ans;
}
void getArray(int n){
    int i = 0;
    while(i < n)
        cin >> arr[i++];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        getArray(n);
        cout << getXoR(n) << endl;
    }
}