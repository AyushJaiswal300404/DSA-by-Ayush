#include <iostream>
using namespace std;

void reverseString(string& str,int i,int j){
    //base case
    if(i>j)
        return;
    //recursive case
    swap(str[i],str[j]);
    i++;
    j--;
    reverseString(str,i,j);
}

bool checkPalindrome(string& str,int i,int j){
    //base case
    if(i>j)
        return true;
    //recursive case
    if (str[i]!=str[j])
        return false;
    else{
        return checkPalindrome(str,i+1,j-1);
    }

}

int power(int a, int b){
    //base case
    if(b==0)
        return 1;
    if(b==1)
        return a;
    //recursive case
    int ans =power(a,b/2);
    if (b%2==0)
        return ans*ans;
    else
        return a*ans*ans;

}

void bubbleSort(int *arr,int n){
    //base case
    if(n==0||n==1)
        return;
    //preprocessing
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    //recursive call
    bubbleSort(arr,n-1);
}

int main(){ 
    string name= "babbab";
    //bool isPalindrome = checkPalindrome(name,0,name.length()-1);
    //reverseString(name,0,name.length()-1);
    //cout<<name<<endl;
    //cout<<isPalindrome<<endl;
    int a,b;
    //cin >>a>>b;

    //int ans= power(a,b);
    //cout<<ans<<endl;
    int arr[5]={5,4,3,2,1};
    bubbleSort(arr,5);
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}