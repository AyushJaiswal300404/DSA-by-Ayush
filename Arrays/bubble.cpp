#include <iostream>
using namespace std;    

//sort by comparing adjacent elements and swapping them if they are in wrong order and
//after each round the largest element is placed at the end and rounds= n-1

void bubbleSort(int arr[], int n) {
    // Loop over each element in the array except the last one
    for (int i = 0; i < n - 1; i++) {
        // Loop over the array up to the unsorted part
        //optimisation through bool
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    bubbleSort(arr, 5);
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

// space complexity: O(1)
// time complexity: O(n^2) [best case=O(n) when array is already sorted]
// stable: yes
// use case- when you have to sort a small array