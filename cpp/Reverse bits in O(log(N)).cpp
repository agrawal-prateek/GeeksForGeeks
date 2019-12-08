#include<iostream>

using namespace std;

const int BITS=31;
int main(){
    int t;
    cin >> t;
    while(t--){
        unsigned int n;
        int c=BITS;
        cin >> n;
        unsigned int rev=n;
        while(n){
            n >>= 1;
            rev <<= 1;
            rev |= n&1;
            c--;
        }
        rev <<= c;
        cout <<rev<<endl;
    }
}