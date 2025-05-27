#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){ //*arr = arr[]
    //base case
    if(n==1 || n==0)
        return true;
    //recursive case
    if (arr[0]>arr[1])
        return false;
    else{
        bool remainingArray = isSorted(arr+1,n-1);
        return remainingArray;
    }
    
}

bool linearSearch(int *arr, int n, int key){
    //base case
    if(n==0)
        return false;
    if(arr[0]== key)
        return true;
    else{
        bool remainingArray = linearSearch(arr+1,n-1,key);
        return remainingArray;
    }
}

bool binarySearch(int arr[], int s, int e, int key) {
    // Base case
    if (s > e)
        return false;

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
        return true;

    // Recursive case
    if (arr[mid] > key)
        return binarySearch(arr, s, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, e, key);
}

int main(){
    int arr[] = {2,4,6,8,10};
    int n = sizeof(arr)/sizeof(int);
    cout<<isSorted(arr,n)<<endl;
    cout<< "present: "<<binarySearch(arr,0,5,8)<<endl;
    return 0;
}