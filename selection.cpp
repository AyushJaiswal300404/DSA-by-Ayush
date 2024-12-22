#include <iostream>
using namespace std;
  

// sort by putting the smallest element at the beginning and then aftwerds using swap

// Function to perform selection sort on an array
void selectionSort(int arr[], int n) {
    // Loop over each element in the array except the last one
    for(int i = 0; i < n - 1; i++) {
        // Assume the current element is the minimum
        int minIndex = i;
        // Loop over the unsorted part of the array
        for(int j = i + 1; j < n; j++) {
            // If a smaller element is found, update minIndex
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the current element
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    selectionSort(arr, 5);
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

// space complexity: O(1)
// time complexity: O(n^2) [all cases]
// use case- when you have to sort a small array
// stable: no