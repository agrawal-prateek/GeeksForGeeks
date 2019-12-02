/**
There are N stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. Count the number of 
ways, the person can reach the top (order does matter).

Input:
The first line contains an integer 'T' denoting the total number of test cases. 
In each test cases, an integer N will be given.

Output:
For each testcase, in a new line, print number of possible ways to reach Nth 
stair. Answer your output % 10^9+7.

Constraints:
1<=T<=105
1<=N<=105

Example:
Input:
3
4
10
24
Output:
5
89
75025
*/

#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	int t, n;
	int fib[100001] = {0};
	fib[0] = fib[1] = 1;
	for(int i=2; i<100001; i++){
	    fib[i] = (fib[i] + (fib[i-1] + fib[i-2]) % MOD) % MOD;
	}
	cin >> t;
	while(t--){
	    cin >> n;
	    cout << fib[n] << endl;
	}
	return 0;
}