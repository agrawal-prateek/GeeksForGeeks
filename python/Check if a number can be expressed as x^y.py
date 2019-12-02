"""
Given a positive integer n, find if it can be expressed as xy where y > 1 and x > 0 and x and y both are both integers.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow . Each test cases contains an integer N.

Output:
For each test case in a new line print 1 if the number can be expressed as  xy else print 0.

Constraints:
1<=T<=1000
1<=n<=100

Example:
Input:
2
8
5
Output:
1
0
"""
from math import sqrt

if __name__ == "__main__":

    t = int(input().strip())
    for _ in range(t):
        n = int(input().strip())
        if n == 1:
            print(1)
            continue
        x = int(sqrt(n))
        y = 2
        while x > 1:
            cal = x ** y
            if cal == n:
                print(1)
                break
            elif cal < n:
                y += 1
            else:
                x -= 1
        else:
            print(0)
