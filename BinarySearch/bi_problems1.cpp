#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> arr, int n, int key) {
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2; // Update mid inside the loop
        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1; // Move to the left half
        } else if (arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int lastOcc(vector<int> arr, int n, int key) {
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2; // Update mid inside the loop
        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1; // Move to the right half
        } else if (arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    pair<int, int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    return p;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int n = arr.size();
    int k = 2;
    pair<int, int> result = firstAndLastPosition(arr, n, k);
    cout << "First Occurrence: " << result.first << ", Last Occurrence: " << result.second << endl;
    return 0;
}