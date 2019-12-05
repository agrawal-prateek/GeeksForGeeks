/*
Given an integer array A of N elements. You need to find the sum of two elements such that sum is 
closest to zero.

Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N, denoting the size of array. Each test case consist of a N 
integers which are the array elements.

Output:
Print the requiired sum which is closest to zero.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103
-106 ≤ a[i] ≤ 106

Example:
Input:
3
3
-8 -66 -60  
6
-21 -67 -37 -18 4 -65  
2
-24 -73

Output:
-68
-14
-97

Explanation:
Testcase 1: Sum of two elements closest to zero is -68 using numbers -60 and -8.
*/

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int twoMinEleSum(int *arr, int n)
{
    int m1 = INT_MAX, m2 = INT_MAX;
    for (int i = 0; i < n; i++)
        if (arr[i] <= m1)
        {
            m2 = m1;
            m1 = arr[i];
        }
        else if (arr[i] < m2)
            m2 = arr[i];
    return m1 + m2;
}
int twoMaxEleSum(int *arr, int n)
{
    int m1 = INT_MIN, m2 = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] >= m1)
        {
            m2 = m1;
            m1 = arr[i];
        }
        else if (arr[i] > m2)
            m2 = arr[i];
    return m1 + m2;
}
void getArray(int arr[], int n)
{
    int i = 0;
    while (i < n)
        cin >> arr[i++];
}
int getClosestToZeroElement(int arr[], int n)
{
    bool allPositive = true, allNegative = true;
    for (int i = 0; i < n; i++)
    {
        if (allPositive && arr[i] < 0)
            allPositive = false;
        if (allNegative && arr[i] > 0)
            allNegative = false;
        if (!allNegative && !allPositive)
            break;
    }
    if (allPositive)
        return twoMinEleSum(arr, n);
    else if (allNegative)
        return twoMaxEleSum(arr, n);
    else
    {
        sort(arr, arr + n);
        int l = 0, r = n - 1, minSum = INT_MAX, sum;
        while (l < r)
        {
            sum = arr[l] + arr[r];
            if (abs(sum) < abs(minSum))
                minSum = sum;
            if (sum < 0)
                l++;
            else
                r--;
        }
        return minSum;
    }
}
int main()
{
    int t, arr[1000];
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        getArray(arr, n);
        cout << getClosestToZeroElement(arr, n) << endl;
    }
}