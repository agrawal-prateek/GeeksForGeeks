#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class MinHeap{
public:
    int *arr;
    int capacity;
    int size;

    MinHeap(int cap){
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }
    void setRoot(int ele){
        arr[0] = ele;
    }
    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }
    int min(){
        if(size > 0)
            return arr[0];
        else
            return INT_MAX;
    }
    void insert(int ele){
        int index = size;
        arr[index] = ele;
        size++;

        while(index >= 0 && arr[parent(index)] > arr[index]){
            int temp = arr[parent(index)];
            arr[parent(index)] = arr[index];
            arr[index] = temp;
            index = parent(index);
        }
    }
    void heapify(int index){
        int l = left(index);
        int r = right(index);
        int smallest = index;
        if(l < size && arr[l] < arr[smallest])
            smallest = l;
        if(r < size && arr[r] < arr[smallest])
            smallest = r;
        if(smallest != index){
            int temp = arr[smallest];
            arr[smallest] = arr[index];
            arr[index] = temp;
            heapify(smallest);
        }
    }
};
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        MinHeap heap(k);
        for(int i=0; i < k; i++)
            heap.insert(v[i]);
        for(int i=k; i<n; i++){
            if(v[i] > heap.min()){
                heap.setRoot(v[i]);
                heap.heapify(0);
            }
        }
        int* arr = heap.arr;
        sort(arr, arr + k, greater<int>());
        for(int i=0; i<k; i++)
            cout<<arr[i] << " ";
        cout << endl;
    }
    return 0;
}