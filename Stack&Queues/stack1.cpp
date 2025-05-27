#include<iostreaM>
#include<stack>
using namespace std;

class Stack{
    //properties of the stack
    public:
        int *arr;
        int top;
        int size;

    //behaviour of the stack
    Stack(int size){
        this->size=size;
        arr = new int[size];
        top = -1;
    }

    void push(int x){
        if(top == size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }

    int peek(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

//stack works on the principle of LIFO (Last In First Out)
int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.isEmpty()<<endl;
    /*
    
    //creating a stack
    stack<int> s;

    //pushing elements into the stack
    s.push(10);
    s.push(20);

    //poping elements from the stack
    s.pop();

    //printing the top element of the stack (peek)
    cout<<s.top()<<endl;

    //checking if the stack is empty
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack is not empty"<<endl;
    }
    //size of the stack
    cout<<"Size of the stack is: "<<s.size()<<endl;

    return 0;
    */
}