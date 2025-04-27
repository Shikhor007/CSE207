#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    pair<int ,int> p1 = {1, 2}; //pair of integers
    pair<string ,int> p2 = {"shikhor", 1}; //pair of string and integer
    cout << "1st element of p1 " << p1.first << " " << "2nd element of p1 " << p1.second << endl; //output: 1 2
    pair<int, pair<char, int>> p3 = {1, {'Z', 25}};
    cout << "1st element of p3 " << p3.first << " " << " and 2nd element of p3 " << p3.second.first << " " << p3.second.second << endl;
    //output: 1 Z 25
    
    vector<pair<int, int> > vec = {{1, 2}, {3, 4}, {5, 6}}; //vector of pairs
    vec.push_back({7, 8}); 
    vec.emplace_back(9, 10); 
    //push_back command thinks there is already a pair of 2 elements in the vector and adds another pair of 2 elements
    //emplace_back command makes a pair of 2 elements and adds it to the vector

    for (auto/*pair<int, int>*/ p : vec) {
        cout << p.first << " " << p.second << endl; //output: 1 2 3 4 5 6
    }


    return 0;
}