#include <iostream>
using namespace std;

void sortTwo(int arr[], int n){
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

void printArray(int arr[],int n){
    for(int i =0;i<n;i++){
        
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[8] = {0, 1, 2, 0, 1, 2, 0, 1};
    sortTwo(arr, 8);
    printArray(arr, 8);
    return 0;
}