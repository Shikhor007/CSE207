#include<iostream>
using namespace std;

template <typename Type>
class Node{
public:
    Type data;
    Node<Type> *next;

    //constructor
    Node(Type value){
        data=value;
        next = NULL;
    }
};

template <typename Type>
class Stack{
private:
    Node<Type> *top;
    int maxSize, length=0;
public:
    // constructor
    Stack(int len=10000){
        maxSize=len;
        top=NULL;
    }
    // method to check if a stack is full or not
    bool isFull(){
        if(length==maxSize)
            return true;
        else
            return false;
    }
    //method to check if a stack is empty or not
    bool isEmpty(){
        if(top==NULL)
            return true;
        else
            return false;
    }
    //method to push an element to a stack
    void push(Type value){
        if (isFull()){
            cout<<"Stack overflow... Can not push a new element!!"<<endl;
            return;
        }
        else{
            Node<Type> *temp = new Node<Type>(value);
            temp->next = top;
            top = temp;
            length++;
            return;
        }
    }
    //method to remove an element from the top position
    Type pop(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
            return Type();
        }
        else{
            Node<Type> *temp;
            temp = top;
            top = top->next;
            Type val = temp->data;
            delete temp;
            length--;
            return val;
        }
    }
    //method to get the value at the top position without removing it
    Type getTop(){
        return top->data;
    }
    //method to get the length of the stack
    int getLength(){
        return length;
    }
    //method to get the maximum length of the stack
    int getMaxLength(){
        return maxSize;
    }
    // Destructor (to free memory)
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main()
{
    Stack<int> stk;
    stk.push(10);
    stk.push(8);
    cout<<stk.getLength()<<endl;
    stk.push(2);
    stk.push(10);
    stk.pop();
    cout<<"Value at top " << stk.getTop()<<endl;
    return 0;
}
