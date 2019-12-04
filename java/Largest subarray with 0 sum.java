/*
Given an array having both positive an negative integers. The task is to complete the function 
maxLen() which returns the length of maximum subarray with 0 sum. The function takes two arguments 
an array A and n where n is the size of the array A.

Input:
The first line of input contains an element T denoting the number of test cases. Then T test cases 
follow. Each test case consist of 2 lines. The first line of each test case contains a number 
denoting the size of the array A. Then in the next line are space separated values of the array A.

Output:
For each test case output will be the length of the largest subarray which has sum 0.

User Task:
Sinec this is a functional problem you don't have to worry about input, you just have to complete 
the function maxLen().

Constraints:
1 <= T <= 100
1 <= N <= 100
-1000 <= A[] <= 1000

Example:
Input
1
8
15 -2 2 -8 1 7 10 23

Output
5

Explanation
Testcase 1: In the above test case the largest subarray with sum 0 will be -2 2 -8 1 7.
*/

import java.util.*;

class MaxLenZeroSumSub {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T > 0) {
            int n = sc.nextInt();
            int arr[] = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = sc.nextInt();

            GfG g = new GfG();
            System.out.println(g.maxLen(arr, n));
            T--;
        }

    }
}

class GfG {
    int maxLen(int arr[], int n) {

        int maxLength = 0, prefixSum = 0;
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            if (prefixSum == 0)
                maxLength = i + 1;
            Integer index = map.get(prefixSum);
            if (index == null)
                map.put(prefixSum, i);
            else
                maxLength = Math.max(maxLength, i - index);
        }
        return maxLength;
    }
}