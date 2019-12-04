/*
You have been given an alphanumeric string S, extract maximum numeric value from that string. 
Alphabets will only be in lower case.

Input:
The first line contains a single integer T i.e. the number of test cases. T testcases follow. The 
first and only line consists of a String S.

Output: 
For each testcase, in a new line, print the Maximum number extracted from the string S.

Constraints:
1 <= T <= 100
2 <= |S| <= 200

Example:
Input:
3
100klh564abc365bg
abvhd9sdnkjdfs
abchsd0sdhs
Output:
564
9
0

Explanation:
Test Case 1: The maximum number found in the string is "564".  
*/

#include <iostream>
using namespace std;

string getMax(string maxString, string currString){
    int leadingZeros = 0;
    for (int i = 0; i < currString.length(); i++){
        if (currString[i] == '0')
            leadingZeros ++;
        else
            break;
    }
    if (leadingZeros > 0)
        currString = currString.erase(0, leadingZeros);
    if (currString.length() < maxString.length())
        return maxString;
    if (currString.length() > maxString.length())
        return currString;
    for (int i = 0; i < maxString.length(); i++)
        if(maxString[i] > currString[i])
            return maxString;
        else if(maxString[i] < currString[i])
            return currString;
    return maxString;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, maxString = "0", currString="";
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >='0' && s[i] <= '9' )
                currString += s[i];
            else if (currString.length() > 0) {
                maxString = getMax(maxString, currString);
                currString = "";
            }
        }
        if (currString.length() > 0)
            maxString = getMax(maxString, currString);
        cout << maxString << endl;
    }
}