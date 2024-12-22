#include <iostream>
#include <string>
using namespace std;

char getMaxOccurringChar(string str) {
    int arr[26] = {0}; // Array to store the frequency of each character

    // Count the frequency of each character
    for (char ch : str) {
        int number = 0;
        if (ch >= 'a' && ch <= 'z') {
            number = ch - 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            number = ch - 'A';
        }
        arr[number]++;
    }

    // Find the character with the maximum frequency
    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }

    char finalAns = 'a' + ans;
    return finalAns;
}

int main() {
    string str = "crrrrrr";
    char result = getMaxOccurringChar(str);
    cout << "The most frequent character is: " << result << endl;
    return 0;
}