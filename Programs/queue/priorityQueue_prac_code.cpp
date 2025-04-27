#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(20);
    //in priority queue, elements are sorted. eg: here 30 20 10
    while (!pq.empty()) {
        cout << pq.top() << " "; // Output: 30 20 10
        pq.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(30);
    pq1.push(10);
    pq1.push(20);
    while (!pq1.empty()) {
        cout << pq1.top() << " "; // Output: 10 20 30
        pq1.pop();
    }
    cout << endl;

}