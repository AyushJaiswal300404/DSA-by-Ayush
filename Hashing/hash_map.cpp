#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    // number hashing
    int n;
    cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    unordered_map<int,int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    int q; //q denotes number of queries
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        //fetch
        cout<<mpp[num]<<endl;
    }
}