#include<iostream>
using namespace std;

class Stack{
    public:
    int top;
    int size;
    int *arr;

    // constructor
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // push function
    void push(int element)
    {
        if ((size - top) > 1)
        {
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack is full."<<endl;
        }
    }

    // pop function
    void pop()
    {
        if(top > -1){
            top--; 
        }
        else{
            cout<<"Stack is empty."<<endl;
        }
    }

    // return top element
    int peek()
    {
        if (top > -1)
        {
            return arr[top];
        }
        else{
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        
    }

    //  check empty or not
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else{
            return false;
        }
        
    }
};



int main()
{
    Stack st(5);

    st.push(22);
    st.push(2);
    st.push(5);

    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;

    return 0;
}
