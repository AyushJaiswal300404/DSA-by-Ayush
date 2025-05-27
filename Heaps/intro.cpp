#include<iostream> 
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    void insert(int val){
        size=size+1;
        int index = size;
        arr[index] = val;
        while(index >1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletefromHeap(){
        if(size==0){
            cout<<"Heap is empty"<<endl;
            return;
        }
        arr[1] = arr[size];
        size = size - 1;
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;

            if(leftIndex <size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i ;
    int right = 2 * i +1;

    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main(){
    // heap h;
    // h.size=0;
    // h.insert(10);
    // h.insert(20);
    // h.insert(30);
    // h.insert(40);
    // h.insert(50);
    // h.print();
    // h.deletefromHeap();
    // h.print();
    int arr[100] = {-1, 10, 20, 30, 40, 50};
    int n = 5; // Size of the heap
    for(int i=n/2; i>=1; i--){
        heapify(arr, n, i);
    }
    cout << "Heap after heapify: ";
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr, n);
    cout << "Sorted array: ";
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
