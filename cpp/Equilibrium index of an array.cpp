#include <iostream>
using namespace std;
int eq(int arr[], int n, int sum, int ls){
    for(int i=0; i<n; i++){
       
        sum -= arr[i];
        if(sum == ls)
            return i+1;
        ls += arr[i];
    }
    return -1;
}
int main() {
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    int arr[n], sum=0;
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	        sum += arr[i];
	    }
	    if(n == 1)
	        cout<<1<<endl;
	    else
	        cout<<eq(arr, n, sum, 0) << endl;
	}
	return 0;
}