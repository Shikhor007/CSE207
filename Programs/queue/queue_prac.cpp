#include <iostream>
using namespace std;

template <typename Type>
class Node{
public:
    Type data;
    Node<Type> *next;

    Node(Type value){
        data = value;
        next = NULL;
    }
};

template <typename Type>
class Queue{
private:
    Node<Type> *frontPos, *rearPos;
    int maxLength, length = 0;
public:
    Queue(int len = 100){
        maxLength = len;
        frontPos = NULL;
        rearPos = NULL;
    }

    bool isEmpty(){
        if (frontPos == NULL)
            return true;
        else
            return false;
    }

    bool isFull(){
        if (length == maxLength)
            return true;
        else
            return false;
    }

    int getLength(){
        return length;
    }

    void push(Type value){
        if (isFull()){
            cout << "Queue is full... can not insert a new element" << endl;
            return;
        }
        else{
            Node<Type> *temp = new Node<Type>(value);
            if (isEmpty()){
                frontPos = temp;
                rearPos = temp;
            }
            else{
                rearPos->next = temp;
                rearPos = temp;
            }
            length++;
            return;
        }
    }

    Type pop(){
        if (isEmpty()){
            cout << "Queue is empty... cannot pop an element" << endl;
            return Type();
        }
        else{
            Node<Type> *temp = frontPos;
            Type value = frontPos->data;
            if (getLength() == 1){               
                frontPos = NULL;
                rearPos = NULL;               
            }
            else{
                frontPos = frontPos->next;
            }
            length--;
            return value;
        }
    }

    Type getFront(){
        if (isEmpty()){
            cout << "Queue is empty ... cannot get front element" << endl;
            return Type();
        }
        else{
            return frontPos->data;
        }
    }

    Type getRear(){
        if (isEmpty()){
            cout << "Queue is empty ... cannot get rear element" << endl;
            return Type();
        }
        else{
            return rearPos->data;
        }
    }

    int getSize(){
        return maxLength;
    }
    
    ~Queue(){
        while (!isEmpty())
            pop();
    }
};

int main(){
    Queue<char> q(9);
    q.push('S');
    q.push('H');
    q.push('I');
    q.push('K');
    q.push('H');
    q.push('O');
    q.push('R');
    cout << "The Front element: " << q.getFront() << endl;
    cout << "The Rear element: " << q.getRear() << endl;
    cout << "Length of queue: " << q.getLength() << endl;
    cout << "Max size of queue: " << q.getSize() << endl;
    while (!q.isEmpty()){
        cout << q.pop();
    }
    cout << endl;
    cout << "Queue is empty now" << endl;
    return 0;
}