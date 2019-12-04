/**
 * All elements appears three times except one element. Find that
 */
#include <iostream>
#define INT_SIZE 32
using namespace std;

int getSingleNumber(int arr[], int n)
{
    int num = 0;
    for (int bit = 0; bit < INT_SIZE; bit++)
    {
        int ones = 0;
        for (int i = 0; i < n; i++)
            ones += (arr[i] & (1 << bit)) >> bit;
        num |= ((ones % 3) << bit);
    }
    return num;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << getSingleNumber(arr, n) << endl;
    }
    return 0;
}