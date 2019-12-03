/*
A number is called faithful if you can write it as the sum of distinct powers of 7. 
e.g.,  2457 = 7 + 72 + 74

If we order all the faithful numbers, we get the sequence 1 = 70, 7 = 71, 8 = 70 + 71, 49 = 72, 50
 = 70 + 72 . . . and so on.

Given some value of N, you have to find the Nth faithful number.

Input: 
The first line of input contains a single integer T denoting the number of test cases. Then T test 
cases follow. Each test case consists of one line. The line consists of a positive integer N.

Output:

Corresponding to each test case, in a new line, print the value of the Nth faithful number


Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106               


Example:

Input
3
3
7
100

Output
8
57
134505
*/

#include<iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s="";
        while(n>0){
            int x=n%2;
            s=s+to_string(x);
            n>>=1;
        }
        long p=0;
        long f=1;
        for(int i=0;i<s.size();i++){
            p+=(s[i]-48)*f;
            f=f*7;
        }
        cout<<p<<endl;
    }
	return 0;
}