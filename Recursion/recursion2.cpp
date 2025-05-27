#include <iostream>
using namespace std;

void reachHome(int src, int dest){
    //base case
    if(src==dest){
        cout<<"Reached Home"<<endl;
        return;
    }
    //preprocessing
    src++;
    //recursive case
    reachHome(src,dest);
}

int climbStairs(int n){
    //base case
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    //recursive case
    int ans = climbStairs(n-1)+climbStairs(n-2);
    return ans;

}

int main(){
    int des =10;
    int src=1;
    cout<<endl;
    //reachHome(src,des);
    cout<<climbStairs(5);
    return 0;
}