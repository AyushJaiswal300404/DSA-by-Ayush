//swap alternate

#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlt(int arr[],int size){

    for(int i=0; i<size;i+=2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);
        }
    }
}
//sort zero-one
void sortOne(int arr[], int n){
    int left=0;
    int right=n-1;
    while(left<right){
        while(arr[left]==0 && left<right){
            left++;
        }
        while(arr[right]==1 && left<right){
            right--;
        }
        swap(arr[left],arr[right]);
        left++;
        right--;
    }

}

int main(){
    //int arr[6]= {1,3,2,7,11,8};
    //swapAlt(arr,6);
    int arr[8]={1,1,0,0,1,0,0,1};
    sortOne(arr,8);
    printArray(arr,8);
}