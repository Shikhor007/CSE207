#include <iostream>
using namespace std;

template <typename Type>
class Node{
public:
    Type data;
    Node<Type> *next;

    Node (Type value){
        data = value;
        next = NULL;
    }
};

template <typename Type>
class Stack{
private:
    Node<Type> *top;
    int maxSize, length=0;
public:
    Stack (int len=100){
        top = NULL;
        maxSize = len;
    }

    bool  isFull(){
        if (maxSize == length)
            return true;
        else
            return false;
    }

    bool isEmpty(){
        if(top == NULL)
            return true;
        else
            return false;
    }

    void push(Type value){
        if (isFull()){
            cout << "Stack Overflow" << endl;
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

    Type pop(){
        if (isEmpty()){
            cout << "Stack Underflow" << endl;
            return Type();
        }
        else{
            Node<Type> *temp = top;
            top = top->next;
            Type value = temp->data;
            delete temp;
            length--;
            return value;
        }
    }

    Type getTop(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return Type();
        }
        else{
            return top->data;
        }
    }

    int getLength(){
        return length;
    }

    int getMaxSize(){
        return maxSize;
    }

    ~Stack(){
        while (!isEmpty())
            pop();
    }
};

int main(){
    Stack<char> s(7);
    s.push('S');
    s.push('H');
    s.push('I');
    s.push('K');
    s.push('H');
    s.push('R');
    cout << "length of stack: " << s.getLength() << endl;
    cout << "max size of stack: " << s.getMaxSize() << endl;
    cout << "top element of stack: " << s.getTop() << endl;
    cout << "popped element: " << s.pop() << endl;
    cout << "top element of stack: " << s.getTop() << endl;
    return 0;
}
