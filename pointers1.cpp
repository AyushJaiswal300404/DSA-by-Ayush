#include<iostream>
using namespace std;

int main(){
    int num=5;
    cout <<num<<endl;
    cout <<&num<<endl;

    int *ptr = &num;
    /* Same as:
        int *ptr =0;
        ptr=&num;
    */
    

    //*ptr is the value at the address stored in p == num
    cout <<ptr<<endl;
    cout <<*ptr<<endl;
    cout<<sizeof(num)<<endl;
    cout<<sizeof(ptr)<<endl;
    cout<<(*ptr=*ptr+1)<<endl;
    cout<<(ptr=ptr+1)<<endl;//add by 4 to go to next integer

}