/**
Given an array A of positive integers. Find the maximum sum of a subsequence
such that no two numbers in the sequence should be adjacent in the array.

Input:
The first line of input contains an integer T denoting the number of test 
cases. The first line of each test case is N, size of array. The second line of 
each test case contains N elements.

Output:
Print the maximum sum of a subsequence.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ci ≤ 107

Example:
Input:
2
6
5 5 10 100 10 5
4
3 2 7 10

Output:
110
13
*/


#include<iostream>
using namespace std;

int main(){
    int t, n, i;
    int include_sum, exclude_sum, curr_ele, prev_include_sum;

    cin >> t;
    while(t--){
        cin >> n;
        cin >> include_sum;
        exclude_sum  = 0;
        while(--n){
            cin >> curr_ele;
            prev_include_sum = include_sum;
            include_sum = exclude_sum + curr_ele;
            exclude_sum = max(prev_include_sum, exclude_sum);
        }
        cout << max(exclude_sum, include_sum) << endl;
    }
    return 0;
}