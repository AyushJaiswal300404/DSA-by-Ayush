#include<iostream>
using namespace std;

int main(){
    /*
    // number hashing
    int n;
    cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    int hash[13]={0};
    for(int i=0; i<n; i++){
        hash[arr[i]]+=1;
    }

    int q; //q denotes number of queries
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        //fetch
        cout<<hash[num]<<endl;
    }
    */

   //character hashing
    string s;
    cin>>s;

    //precompute
    int hash[256]={0};
    for(int i=0; i<s.length(); i++){
        hash[s[i]]+=1;
    }

    int q; //q denotes number of queries
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        //fetch
        cout<<hash[ch]<<endl;
    }
    

}