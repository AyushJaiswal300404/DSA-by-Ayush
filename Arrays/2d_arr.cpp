#include <iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    //int arr[3][4];
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    //int arr[3][4] ={1,2,3,4,5,6,7,8,9,10,11,12};
    //taking input row-wise
    /*for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }*/
    //taking input column-wise
    /*for(int j=0;j<4;j++){
        for(int i=0;i<3;i++){
            cin>>arr[i][j];
        }
    }
    */
    //printing 
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    isPresent(arr, 7, 3, 4) ? cout<<"Yes" : cout<<"No";

}