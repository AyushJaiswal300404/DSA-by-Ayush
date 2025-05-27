#include <iostream>
#include <vector>
#include <string>
using namespace std;
//subsequence of a string
void solve(string str, string output, int index, vector<string>& ans){
    //base case
    if(index>=str.size()){
        ans.push_back(output);
        return;
    }
    //exclude'
    solve(str, output,index+1,ans);
    //include
    char element = str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);
}

vector<string> subsequence(string s){
    vector<string> ans;
    string output ="";
    int index =0;
    solve(s,output,index,ans);
    return ans;
}
int main(){
    string s = "abc";
    vector<string> ans = subsequence(s);
    for(auto i: ans){
        cout<<i<<endl;
    }
    return 0;
}