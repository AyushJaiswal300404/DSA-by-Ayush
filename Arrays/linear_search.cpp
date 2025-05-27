#include <iostream>
using namespace std;

bool search(int arr[], int size, int key){
    for(int i=0; i<size;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

int main(){
    int arr[10]={1,2,73,4,56,6,7,8,9,10};

    //whether 15 is present or not
    cout<<"Enter element to search for: "<<endl;
    int key;
    cin>>key;

    bool found = search(arr,10,key);

    if (found){
        cout<<"Key is present"<<endl;
    }else{
        cout<<"Key is not present"<<endl;
    }
    return 0;
}

