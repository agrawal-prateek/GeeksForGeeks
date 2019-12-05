/*
Given an unsorted array of size N. Find the first element in array such that all of its left 
elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be 
required element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases 
follow. Each test case consists of two lines. First line of each test case contains an Integer N 

denoting size of array and the second line contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element present in array 
then print -1.

Constraints:
1 <= T <= 100
3 <= N <= 10^6
1 <= A[i] <= 10^6

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7
Explanation:
Testcase 1 : Elements on left of 5 are smaller than 5 and on right of it are greater than 5.

*/

#include <iostream>
#include <climits>
using namespace std;

int leftMax[1000000];
void getArray(int arr[], int n)
{
    int i = 0;
    while (i < n)
        cin >> arr[i++];
}
int getAns(int *arr, int n)
{
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    int index = -1, rightMin = arr[n - 1], minIndex = INT_MAX;
    for (int i = n - 2; i > 0; i--)
    {
        if (arr[i] >= leftMax[i] && arr[i] <= rightMin)
            minIndex = min(minIndex, i);
        rightMin = min(rightMin, arr[i]);
    }
    return minIndex == INT_MAX ? -1 : arr[minIndex];
}
int main()
{
    int t, arr[1000000];
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        getArray(arr, n);
        cout << getAns(arr, n) << endl;
    }
}