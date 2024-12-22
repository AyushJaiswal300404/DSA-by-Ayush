#include <iostream>
using namespace std;

int partition(int *arr, int s,int e){
    int pivot = arr[s];
    int cnt =0;
    for(int i=s+1; i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    //place pivot at right position
    int pivotIndex = s+cnt;
    swap(arr[pivotIndex],arr[s]);

    //sort left and right part
    int i=s, j=e;
    while(i<pivotIndex && j > pivotIndex){
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i++],arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }
    //partition
    int p= partition(arr,s,e);
    // recursive call
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
 
}

int main(){
    int arr[6]={23,3,5,76,34,23};
    int n=6;
    quickSort(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}

//time complexity: O(nlogn) in average case, O(n^2) in worst case
//space complexity: O(logn) in average case, O(n) in worst case