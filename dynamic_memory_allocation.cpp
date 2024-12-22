#include <iostream>
using namespace std;
 
void update(int &p){
    p = p+1;
}

/*
Bad Practice
int& update2(int &p){
    p = p+1;
    return p;
}
*/
 int getSum(int * arr, int n){
     int sum=0;
        for(int i=0; i<n;i++){
            sum+=arr[i];
        }
        return sum;
 }


int main(){
    //refrence variable = to update value while function call
    int i =5;
    int& j=i;
    cout<<i<<endl;
    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;
    update(i);
    cout<<i<<endl;  
    //update2(i);
    //cout<<i<<endl;

    //Arrays by dynamic memory allocation
    /*
    Size should be specified before hand not at compile time as program can crash(memory by stack)
    int n;
    cin>>n;
    int arr[n];
    */

    //Dynamic memory allocation(memory by heap)
    new char; //name not required
    char *ch = new char;
    sizeof(ch);

    int n;
    cin>>n;
    int *arr= new int[n];

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    
    int ans = getSum(arr,n);
    cout<<ans<<endl;

    delete [] arr; //free memory



}