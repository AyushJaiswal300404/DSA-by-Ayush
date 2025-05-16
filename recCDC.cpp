#include<iostream>
using namespace std;

int fact(int n){
    if(n==0||n==1)
        return 1;
    return n*fact(n-1);
}

int fib(int n){
    if(n==0 || n==1) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    cout<<"Enter n: "<<endl;
    int n;
    cin>>n;
    // for(int i=0;i<n;i++){
    //     cout<<fib(i)<<endl;
    // }
    if(n>=0){
        cout<<fib(n)<<endl;
    }
    
 
}

