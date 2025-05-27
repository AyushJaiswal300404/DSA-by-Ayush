#include <iostream>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}

void update(int *p){
    //address updated inside  function only
     //p = p+1;
     //value updated for all
    *p = *p+1;
}

int main(){
    int arr[10];
    cout<<arr<<endl; //Address of the first element
    cout<<arr[0]<<endl; //Value of the first element
    cout<<&arr[0]<<endl; //Address of the first element
    cout<<*arr<<endl; //Value of the first element
    cout<<*arr+1<<endl; //Value of the first element + 1
    cout<<*(arr+1)<<endl; //Value of the second element
    cout<<arr+1<<endl; //Address of the second element

    //arr[i] = *(arr+i) or i[arr] = *(i+arr)
    int value=5;
    int *p = &value;

    print(p);
    update(p);
    print(p);

    return 0;
}