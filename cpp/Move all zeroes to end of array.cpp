/*
Given an array A of positive integers. Push all the zero’s of a given array to the end of the array.

Input:
The first line contains an integer T denoting the total number of test cases. In each test cases, 
first line is number of elements in array N and next line contains array elements.

Output:
Print the array after shifting all 0's at the end.​

Constraints:
1 <= T <= 100
1 <= N <= 103
0 <= Ai <=103

Example:
Input:
1
5
3 5 0 0 4

Output:
3 5 4 0 0

Explanation:
Testcase 1: All the zeros are moved to last and then array is as shown in the output.
*/

#include<iostream>
using namespace std;

void moveZeroToEnd(int arr[], int n){
    int j=0;
    for(int i=0; i<n; i++)
        if (arr[i] != 0)
            arr[j++] = arr[i];
    while (j < n)
        arr[j++] = 0;
}
void printArr(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void getArray(int arr[], int n){
    int i = 0;
    while(i < n)
        cin >> arr[i++];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        getArray(arr, n);
        moveZeroToEnd(arr, n);
        printArr(arr, n);
    }
}