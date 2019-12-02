"""
Calculate the angle between hour hand and minute hand.

There can be two angles between hands, we need to print minimum of two. Also, we need to print floor of final result
angle. For example, if the final angle is 10.61, we need to print 10.



Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each
test case consists of one line conatining two space separated numbers h and m where h is hour and m is minute.

Output:
Coresponding to each test case, print the angle b/w hour and min hand in a separate line.

Constraints:

1 ≤ T ≤ 100
1 ≤ h ≤ 12
1 ≤ m ≤ 60

Example:

Input
2
9 60
3 30

Output
90
75
"""
t = int(input().strip())
for _ in range(t):
    h, m = [float(x) for x in input().strip().split()]
    if h == 12:
        h = 0
    if m == 60:
        m = 0

    h = (h * 5) + (m / 12)
    angle = 6 * abs(m - h)
    print(int(min(360 - angle, angle)))
