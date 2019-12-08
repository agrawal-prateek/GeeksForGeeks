#include<iostream>
#include<deque>
#include<climits>
using namespace std;

void printMax(int *arr, int n, int k){
    deque<int> Q(k);
    for (int i=0; i<k; i++){
        while(!Q.empty() && arr[Q.back()] < arr[i])
            Q.pop_back();
        Q.push_back(i);
    }
    for(int i=k; i<n; i++){
        cout << arr[Q.front()] << " ";
        while(!Q.empty() && Q.front() <= i - k )
            Q.pop_front();
        while(!Q.empty() && arr[Q.back()] < arr[i])
            Q.pop_back();
        Q.push_back(i);
    }
    if (!Q.empty()){
        cout << arr[Q.front()] << " ";
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i=0; i < n; i++)
            cin >> arr[i];
        printMax(arr, n, k);
    }
}