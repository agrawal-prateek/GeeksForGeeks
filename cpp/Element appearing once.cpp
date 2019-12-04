/*
Given an sorted array A[i] of N positive integers having all the numbers occuring exactly twice,
 except for one number which will occur only once. Find the number occuring only once.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases
follow. The first line of each test case contains a positive integer N, denoting the size of the 
array.
The second line of each test case contains a N positive integers, denoting the elements of the
array.


Output
Print out the singly occuring number.


Constraints
1 <= T  <= 100
0 <   N  <= 100
0 <= A[i] <= 100

Examples 

Input
2
5
1 1 2 5 5
7
2 2 5 5 20 30 30


Output
2
20
 

Expected Complexity

Time : O(N)
*/

#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int n, num=0, temp;
        cin >> n;
        
        int arr[n];
        while(n--){
            cin >> temp;
            num ^= temp;
        }
        cout << num << endl;
    }
	return 0;
}