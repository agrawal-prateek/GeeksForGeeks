# First and last occurrences of X
"""
Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Note: If the number x is not found in the array just print '-1'.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case contains two integers n and x. The second line contains n spaced integers.

Output:
Print index of the first and last occurrences of the number x with a space in between.

Constraints:
1<=T<=100
1<=n,a[i]<=1000

Example:
Input:
2
9 5
1 3 5 5 5 5 67 123 125
9 7
1 3 5 5 5 5 7 123 125

Output:
2 5
6 6
"""
def getFirstIndex(arr, x, n):
    lowest = -1
    l, h = 0, n - 1
    while l <= h:
        mid = (l + h) >> 1
        if arr[mid] == x:
            lowest = mid
            h = mid - 1
        elif x < arr[mid]:
            h = mid - 1
        else:
            l = mid + 1
    return lowest


def getLastIndex(arr, x, n):
    highest = -1
    l, h = 0, n - 1
    while l <= h:
        mid = (l + h) >> 1
        if arr[mid] == x:
            highest = mid
            l = mid + 1
        elif x < arr[mid]:
            h = mid - 1
        else:
            l = mid + 1
    return highest


t = int(input().strip())
for _ in range(t):
    n, x = [int(x) for x in input().strip().split()]
    arr = [int(x) for x in input().strip().split()]
    fi = getFirstIndex(arr, x, n)
    li = getLastIndex(arr, x, n)
    if fi == -1 and li == -1:
        print(-1)
    else:
        print(fi, li)
