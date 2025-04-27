#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    stack<int> s2(s); // Copy constructor
    s2.swap(s); // Swap contents of s and s2
    
    cout << "Top element: " << s.top() << endl; // Output: 30

    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // Output: 20

    cout << "Stack size: " << s.size() << endl; // Output: 2

    return 0;
}