#include <iostream>
#include <stack>
using namespace std;
//Q1: valid parenthesis
bool matches(char top, char close) {
    return (top == '(' && close == ')') ||
           (top == '{' && close == '}') ||
           (top == '[' && close == ']');
}

bool isValidParenthesis(string s) {
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];
        
        // If opening bracket, push to stack
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If closing bracket
        else {
            // If stack is empty, no matching opening bracket
            if(st.empty()) {
                return false;
            }
            
            char top = st.top();
            if(matches(top, ch)) {
                st.pop();  // Fixed: pop from stack, not string
            }
            else {
                return false;
            }
        }
    }
    
    // Stack should be empty if all brackets matched
    return st.empty();  // Fixed: return true if stack empty
}
//Q2: reverse a string using stack
int main(){
    string str="Harry";

    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        s.push(ch);
    }
    string rev = "";
    while(!s.empty()){
        char ch = s.top();
        rev.push_back(ch);
        s.pop();
    }
    cout<<rev<<endl;
}