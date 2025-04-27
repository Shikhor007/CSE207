#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);

    cout << "lower bound = " << *(s.lower_bound(3)) << endl;//lower_bound returns an iterator to the first element that is not less than 3
    cout << "lower bound = " << *(s.lower_bound(9)) << endl;//if there is no element greater than or equal to 7, it returns the last element in the set
    cout << "upper bound = " << *(s.upper_bound(3)) << endl;//upper_bound returns an iterator to the first element that is greater than 3
    cout << "upper bound = " << *(s.upper_bound(6)) << endl;//if there is no element greater than 6, it returns the end iterator
    /*lower bound takes elements which are equal to and lower 
    but upper bound takes only the greater number*/
    
    cout << "set size: " << s.size() << endl;
    s.insert(2);
    s.insert(3);
    //duplicates are not inserted
    for (auto p : s) {
        cout << p << " ";
    }
    


    return 0;
}