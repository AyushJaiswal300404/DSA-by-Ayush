#include <iostream>
using namespace std;

int main(){
    int row, col;
    cin >> row;
    cin >> col;
    int **arr = new int*[row];

    for(int i=0;i<row;i++){
        arr[i] = new int[col];
    }
    //creation done

    //taking input
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }

    //printing output
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //always free memory after use
     for(int i=0;i<row;i++){
        delete [] arr[i];
    }
    delete []arr;
}