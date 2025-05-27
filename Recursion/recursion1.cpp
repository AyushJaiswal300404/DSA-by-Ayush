#include <iostream>
using namespace std;

int factorial(int n){
    //base case
    if(n==0)
        return 1;
    //recursive case
    return n*factorial(n-1);
}

int power(int n){
    //base case
    if(n==0)
        return 1;
    //recursive relation
    int smallerProblem = power(n-1);
    int biggerProblem = 2*smallerProblem;
    return biggerProblem;
}

int main(){
    int n;
    cin>>n;

    int ans=factorial(n);
    cout<<ans<<endl;

    int ans2= power(n);
    cout<<ans2<<endl;
    return 0;
}