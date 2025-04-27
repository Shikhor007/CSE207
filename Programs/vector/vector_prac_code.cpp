#include<iostream>
#include<vector>
using namespace std;

int main() {
    // vector<int> vec1(3,10); //vector of size 3 with all elements initialized to 10
    // vector<int> vec2(vec1); //copy constructor, vec2 is a copy of vec1
    vector<int> vec; //0
    vector<int>:: iterator it; //iterator to traverse the vector
    // vector<int>:: iterator it = vec.begin(); //iterator to the first element of the vector
    vector<int>:: reverse_iterator rit; //reverse iterator to traverse the vector in reverse order
    // vector<int>:: reverse_iterator rit = vec.rbegin(); //reverse iterator to the last element of the vector
    //vector<int>:: reverse_iterator rit; it can be also replaced with 'auto'; eg: auto it = vec.begin();
    vec.push_back(1); //1 --> size=1, capacity=1
    vec.push_back(2); //2 --> size=2, capacity=2
    vec.push_back(3); //3 --> size=3, capacity=4
    vec.push_back(4); //4 --> size=4, capacity=4
    vec.push_back(5); //5 --> size=5, capacity=8
    vec = {1, 2, 3, 4, 5}; does same as above
    vec.emplace_back(6);
    //output: 1 2 3 4 5 6
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    vec.pop_back(); //removes the last element
    //output: 1 2 3 4 5

    /*if the vector is full and we need to add another element,
    the capacity will increase by 2x
    Suppose the vector is full with 2 element and we need to 
    add another element, the capacity will increase by 2x = 4*/ 
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    vec.erase(vec.begin() + 1); //removes the element at index 1(2nd element)
    //output: 1 3 4 5 6
    vec.erase(vec.begin() + 1, vec.begin() + 3); //removes the elements from index 1 to index 3(2nd and 3rd element)
    //output: 1 4 5 6
    
    vec.insert(vec.begin() + 1, 100); //inserts 100 at index 1(2nd position)
    //output: 1 100 4 5 6
    cout << "the last element is: " << *(vec.end() - 1) << endl; //vector end points element after the last element
    cout << "the first element is: " << *(vec.rend() - 1) << endl; //vector rend points element before the first element
    cout << "the last element is: " << *(vec.rbegin()) << endl; //vector rbegin points to the last element
    cout << vec.at(2) << endl; //accessing the 3rd element using at() function
    cout << vec[2] << endl; //accessing the 3rd element using [] operator
    cout << "val at index 2: " << vec.at(2) << " or " << vec[2] << endl; //accessing the 3rd element using at() function
    
    cout << vec.size() << endl; //number of elements in the vector
    cout << vec.capacity() << endl; // number of element it can hold

    /*front() and back() is used to directly get the values but
    begin() and end() are usd for iteration*/
    
    cout << "front: " << vec.front() << endl; //first element of the vector
    cout << "back: " << vec.back() << endl; //last element of the vector 
    
    vec.clear(); //clears the vector, size becomes 0

    cout << "size after clear: " << vec.size() << endl; //size becomes 0
    cout << "capacity after clear: " << vec.capacity() << endl; //capacity remains same
    cout << "is empty: " << vec.empty() << endl; //returns true(1) if the vector is empty, false(0) otherwise
    return 0;

}
