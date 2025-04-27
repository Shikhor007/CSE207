#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Front element: " << q.front() << endl; // Output: 10
    cout << "Back element: " << q.back() << endl;   // Output: 30
    
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 20
    
    cout << "Queue size: " << q.size() << endl; // Output: 2
    
    return 0;
}