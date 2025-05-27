#include <iostream>
using namespace std;
 int score = 0; //global variable

void update();

inline int getMax(int &a, int &b){ //no need to call function, directly replaced
    return (a>b)?a:b;
}

void print(int arr[], int n, int start=0){ //default argument, starts from rightmost
    for(int i=start;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int score = 5; //local variable
    cout<<score<<endl;
    update();
    cout<<score<<endl;
    int a=1,b=2,ans;
    ans =getMax(a,b);

    a=a+3;
    b=b+1;
    ans =getMax(a,b);

    int arr[5]={1,2,3,4,5};
    int size=5;
    print(arr,size,2);
    print(arr,size);
    return 0;

    
}

void update(){
    score=9;
}