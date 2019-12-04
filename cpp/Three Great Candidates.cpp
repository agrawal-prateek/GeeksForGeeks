/*
The hiring team of Google aims to find 3 candidates who are great collectively. Each candidate has
 his or her ability expressed as an integer. 3 candidates are great collectively if product of 
 their abilities is maximum. Given abilities of N candidates, find the maximum collective ability 
 from the given pool of candidates.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases 
follows. First line of each test case conatins an interger N  denoting the number of candidates.
The second line of each test case contains N space separated elements denoting the ablities of candidates.

Output:
Corresponding to each test case, print the desired output(maximum collective ability of three 
candidates) in a newline.

Constraints:
1 ≤ T ≤ 100
3 ≤ N ≤ 107
-105 ≤ ability ≤ 105

Example:
Input
1
6
0 -1 3 100 70 50

Output:
350000

Explanation:
Testcase 1: 70*50*100 = 350000 which is the maximum possible.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, i = 0, ele;
        long mx1=INT_MIN, mx2=INT_MIN, mx3=INT_MIN;
        long mn1=INT_MAX, mn2=INT_MAX;
        
        cin >> n;
        while(i++ < n){
            cin >> ele;
            if      (ele > mx1) {mx3=mx2;mx2=mx1;mx1=ele;}
            else if (ele > mx2) {mx3=mx2;mx2=ele;}
            else if (ele > mx3) mx3=ele;
            
            if (ele < mn1) {mn2=mn1;mn1=ele;}
            else if (ele < mn2) mn2=ele;
        }
        cout << max(mx1 * mx2 * mx3, mn1 * mn2 * mx1) << endl;
    }
}