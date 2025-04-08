#include<iostream>
using namespace std;

// class representing the blueprint of each Node
class Node{
public:
    int data;
    Node *next;

    //constructor to initialize node
    Node(int value){
        data = value;
        next = NULL;
    }
};

class LinkedList{
private:
    Node *head;
public:
    LinkedList(){ //initialize an empty list
        head = NULL;
    }

    //Function to insert an element to the end
    void insertAtEnd(int value){
        Node *newNode = new Node(value);
        if(head == NULL) // if the list is empty
            head = newNode;
        else{
            // traverse the list and insert the node at the end
            Node *temp = head;
            while(temp->next != NULL)
                temp = temp->next;//-- go to the next node
            temp->next = newNode; // insert new node at end
        }
    }
    //function to insert a node at the k-th position
    void insertAtPosition(int value, int k){
        Node *newNode = new Node(value);
        if(k<1){
            cout<<"Invalid position"<<endl;
            delete newNode;
            return;
        }
        if(k==1){  // to insert at 1st position
            newNode->next = head;
            head = newNode;
            return;
        }
        int counter = 1; // to count number of elements we visited
        Node *temp = head;
        //traverse the list
        while(temp->next!=NULL && counter< (k-1) ){
            temp = temp->next;
            counter++;
        }
        /*if after traversing the full list, we don't reach
        our expected position*/
        if(counter != k-1 ){
            cout<<"Position out of range"<<endl;
            delete newNode;
            return;
        }
        //insert the node at k-th position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == value) { // --- if we want to delete the value at head (or first node)
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        // traverse the list unless we find the value in the next node
        while (temp->next != NULL && temp->next->data != value)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Value not found in the list!" << endl;
            return;
        }

        Node* delete_node = temp->next; // next node to be deleted
        temp->next = temp->next->next; //
        delete delete_node;
    }

    // Function to display the list
    void display()
    {
        Node *temp = head;
        while(temp != NULL){
            cout<< temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" <<endl;
    }
    // destructor
    ~LinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList myList;

    myList.insertAtEnd(10);
    myList.insertAtEnd(40);
    myList.insertAtEnd(20);

    myList.display();

    myList.insertAtPosition(50, 3);
    myList.display();

    myList.deleteNode(40);

    myList.display();

    return 0;
}

