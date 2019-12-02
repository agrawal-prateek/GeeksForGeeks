"""
You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow.
The first line of each test case is N.

Output:
For each testcase, in a new line, print the total count of all bits.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103

Example:
Input:
2
4
17
Output:
5
35

Explanation:
Testcase1:
An easy way to look at it is to consider the number, n = 4:
0 0 0 = 0
0 0 1 = 1
0 1 0 = 1
0 1 1 = 2
1 0 0 = 1
Therefore , the total number of bits is 5.
"""
from math import log, ceil

t = int(input().strip())
for _ in range(t):
    n = int(input().strip()) + 1
    bits, totalSetBits = ceil(log(n, 2)), n // 2
    for i in range(1, bits):
        totalGroups = n // (2 ** i)
        groupsForSetBit = totalGroups // 2
        setBits = groupsForSetBit * (2 ** i)
        totalSetBits += setBits + ((n % (2 ** i)) if totalGroups & 1 else 0)
    print(totalSetBits)
