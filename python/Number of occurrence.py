"""
Given a sorted array A of size N and a number X, you need to find the number of occurrences of X in A.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow.
Each testcase contains two lines of input: The first line contains N and X(element whose occurrence
needs to be counted). The second line contains the elements of the array separated by spaces.

Output:
For each testcase, print the count of the occurrences of X in the array, if count is zero then print -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 103
1 <= X <= 103

Example:
Input:
2
7 2
1 1 2 2 2 2 3
7 4
1 1 2 2 2 2 3
Output:
4
-1

Explanation:
Testcase 1: 2 occurs 4 times in 1 1 2 2 2 2 3
Testcase 2: 4 is not present in 1 1 2 2 2 2
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


if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        n, x = [int(x) for x in input().strip().split()]
        arr = [int(x) for x in input().strip().split()]
        li = getLastIndex(arr, x, n)
        fi = getFirstIndex(arr, x, n)
        print(li - fi + 1 if li != -1 else -1)
