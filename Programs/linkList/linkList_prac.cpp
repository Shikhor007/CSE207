#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    
    Node(int value){
        data = value;
        next = NULL;
    }
};
class LinkedList{
private:
    Node *head;
public:
    LinkedList(){
        head = NULL;
    }
    
    void insertAtEnd(int value){
        Node *newNode = new Node(value);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL){
                temp =temp->next;
            }
            temp->next = newNode;
        }
    }
    void insertAtPosition(int value, int pos){
        Node *newNode = new Node(value);
        if (pos < 1){
            cout << "Invalid position" << endl;
            return;
        }
        else if (pos == 1){
            newNode->next = head;
            head = newNode;
            return;
        }
        else {
            int count = 1;
            Node *temp = head;
            while(temp->next != NULL && count < (pos-1)){
                temp = temp->next;
                count++;
            }
            if (temp->next == NULL){
                cout << "Position out of range" << endl;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void deleteNode(int value){
        if(head->data == value){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        while(temp->next != NULL && temp->next->data != value){
            temp = temp->next;
        }
        if(temp->next == NULL){
            cout << "Value not found" << endl;
            return;
        }
        else{
            Node *delete_node = temp->next;
            temp->next = temp->next->next;
            delete delete_node;
        }
    }
    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data;
            if(temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }
    ~LinkedList(){
        Node *temp;
        while(head != NULL){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main(){
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(30);
    list.insertAtEnd(25);
    list.insertAtEnd(19);
    list.insertAtEnd(5);

    list.display();

    list.insertAtPosition(20, 3);
    list.display();

    list.deleteNode(30);
    list.display();
    
    return 0;
}
