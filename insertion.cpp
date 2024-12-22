#include <iostream>
using namespace std;

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        // Shift elements of arr[0..i-1], that are greater than temp, to one position ahead of their current position
        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Place temp at its correct position
        arr[j + 1] = temp;
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    insertionSort(arr, 5);
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

// space complexity: O(1)
// time complexity: O(n^2) [best case=O(n) when array is already sorted]
// stable: yes
// use case- adaptable, when you have to sort a small array