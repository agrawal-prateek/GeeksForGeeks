#include<iostream>
using namespace std;

int main(){
    int t, n, i;
    int include_sum, exclude_sum, curr_ele, prev_include_sum;

    cin >> t;
    while(t--){
        cin >> n;
        cin >> include_sum;
        exclude_sum  = 0;
        while(--n){
            cin >> curr_ele;
            prev_include_sum = include_sum;
            include_sum = exclude_sum + curr_ele;
            exclude_sum = max(prev_include_sum, exclude_sum);
        }
        cout << max(exclude_sum, include_sum) << endl;
    }
    return 0;
}