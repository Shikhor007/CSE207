#include<iostream>

using namespace std;

template<typename Type>
class Node{
public:
    Type data;
    Node<Type> *next;
    //constructor to initialize node
    Node(Type value){
        data = value;
        next = NULL;
    }
};

template<typename Type>
class Queue{
private:
    Node<Type> *frontPosition, *rearPosition;
    int maxLength, length=0;
public:
    //constructor
    Queue(int len=10000){
        maxLength = len;
        frontPosition = NULL;
        rearPosition = NULL;
    }
    //to check if a queue is empty
    bool isEmpty(){
        if(length==0) //or frontPosition==NULL
            return true;
        else
            return false;
    }
    //to check if the queue is full
    bool isFull(){
        if(length==maxLength)
            return true;
        else
            return false;
    }
    //to get the length of the queue
    int getLength(){
        return length;
    }
    //method to insert a new element
    void push(Type value){
        if( isFull() ){
            cout<<"Queue overflow... can not insert a new element"<<endl;
            return;
        }
        else{
            Node<Type> *temp = new Node<Type>(value);
            if(isEmpty()){ // if the queue is empty
                frontPosition = temp; // both the frontPosition and
                rearPosition = temp; //rearPosition get updated
            }
            else{
                /* if the queue is not empty,
                we will add the new element at the rearPosition
                and the rear position will be updated accordingly
                */
                rearPosition->next = temp;
                rearPosition = temp;
            }
            length++;
            return;
        }
    }
    //method to remove top element
    Type pop(){
        if( isEmpty() ){
            cout<<"Queue Underflow..."<<endl;
            return Type();
        }
        else{
            Node<Type> *temp = frontPosition;
            if(getLength()==1){ // if there is only one element in the queue
                frontPosition = NULL;
                rearPosition = NULL;
            }
            else
                frontPosition = frontPosition->next;
            // retrieve the value from the Node
            // that needs to be deleted
            Type value= temp->data;
            delete temp;
            length--;
            return value;
        }
    }
    //to get the front element from the queue
    Type getFront(){
        if( isEmpty() ){
            cout<<"Queue is empty!!!"<<endl;
            return Type();
        }
        else
            return frontPosition->data;
    }
    // destructor
    ~Queue(){
        while( !isEmpty() )
            pop();
    }
};

int main(){
    Queue<char> Q;
    Q.push('P');
    Q.push('U');
    Q.push('J');
    Q.push('A');

    cout<<"Length: "<<Q.getLength()<<endl;

    while(!Q.isEmpty()){
        cout<<Q.getFront();
        Q.pop();
    }
    cout<<endl;  

    cout<<"Length: "<<Q.getLength()<<endl;
    return 0;
}