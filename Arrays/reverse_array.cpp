#include <iostream>
using namespace std;

int reverse(int arr[], int n){
    int start =0;
    int end = n-1;
    while(start<=end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return 0;
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[6]={1,4,6,7,9,8};
    int n=6;

    reverse(arr,n);

    printArray(arr,n);
}