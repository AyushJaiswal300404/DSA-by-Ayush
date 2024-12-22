#include<iostream>
using namespace std;

int getLength(char arr[]){
    int count = 0;
    for(int i = 0; arr[i] != '\0'; i++){
        count++;
    }
    return count;
}

void reverse(char arr[]){
    int s=0;
    int e=getLength(arr)-1;
    while(s<e){
        swap(arr[s++],arr[e--]);
    }
}

char toLower(char ch){
    if(ch>='A' && ch<='Z'){
        return ch - 'A' + 'a';//ch+32
    }
    return ch;
}

int palindrome(char arr[]){
    int s=0;
    int e=getLength(arr)-1;
    while(s<e){
        if(arr[s++]!=arr[e--]){
            return 0;
        }
    }
    return 1;
}



int main(){
    char name[20];
    cout<<"Enter your name: ";
    cin>>name;

    cout<<"Your name is: "<<name<<endl;  //Execution stops at the first space
    cout<<"Length of your name is: "<<getLength(name)<<endl;
    reverse(name);
    cout<<"Reversed name is: "<<name<<endl;
    if (palindrome(name)){
        cout<<"Your name is a palindrome"<<endl;
    }
    else{
        cout<<"Your name is not a palindrome"<<endl;
    }

    return 0;
}