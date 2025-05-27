#include<iostream>
using namespace std;
//Binary Number System
int dtob(int decNum){
    int ans=0,pow=1,rem;
    while(decNum>0){
        rem = decNum%2;
        decNum = decNum/2;
        ans = ans +(rem*pow);
        pow = pow*10;
    }
     return ans;
}

int btod(int biNum){
    int ans=0,pow=1,rem;
    while(biNum>0){
        rem = biNum%10;
        ans +=(rem*pow);
        biNum =biNum/10;
        pow =pow*2;
    }
    return ans;
}

int main(){
    cout<<btod(101)<<endl;
    cout<<dtob(5);
    return 0;
}