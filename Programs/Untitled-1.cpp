#include <iostream>
using namespace std;

class Employee
{   
    public:
    string name;
    int id;

    Employee(string name, int id)
    {
        this->name = name;
        this->id = id;
    }

    void printDetails()
    {
        cout << "The name of the employee is: " << name << endl;
        cout << "The id of the employee is: " << id << endl;
    }
    
};


int main()
{
    int *ptr1;
    char *ptr2;
    cout << "the size of ptr is: "<< sizeof(ptr1) << endl;
    cout << "the size of ptr is: "<< sizeof(ptr2) << endl;
    
    int a = 10;
    int *ptr = &a;
    cout << "The value of a is: " << a << endl;
    cout << "The value of a is: " << *ptr << endl;
    cout << "The address of a is: " << &a << endl;
    cout << "The address of a is: " << ptr << endl;
    cout << "\n\n";

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    cout << "\n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    

    cout << "\n\n";
    Employee emp1 = Employee("John", 101);
    Employee emp2 = Employee("Harry", 202);
    emp1.printDetails();
    emp2.printDetails();

    return 0;
}