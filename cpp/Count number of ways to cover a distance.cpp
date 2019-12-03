/**
 * A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it 
 reach the top.

Input:
The first line of input contains an integer T denoting the number of test
cases. T testcases follow. Each testcase contains one line of input N denoting
the total number of steps.

Output:
For each testcase, in a new line, print the number of ways to reach the top.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 50

Example:
Input:
2
1
5
Output:
1
13
 */

#include <iostream>
using namespace std;

int main(){
    int t, n;

    int ways[51];
    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 2;

    for (int i = 3; i < 51; i++)
        ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];
    cin >> t;

    while (t-- > 0)
    {
        cin >> n;
        cout << ways[n] << endl;
    }
    return 0;
}