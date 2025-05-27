#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    bool valid(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }

    char toLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch - 'A' + 'a'; // ch + 32
        }
        return ch;
    }

    bool palindrome(const string& a) {
        int s = 0;
        int e = a.length() - 1;
        while (s < e) {
            if (a[s++] != a[e--]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s) {
        string temp = "";
        for (int j = 0; j < s.length(); j++) {
            if (valid(s[j])) {
                temp.push_back(s[j]);
            }
        }

        for (int j = 0; j < temp.length(); j++) {
            temp[j] = toLower(temp[j]);
        }

        return palindrome(temp);
    }
};

int main() {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << (sol.isPalindrome(s) ? "True" : "False") << endl;
    return 0;
}