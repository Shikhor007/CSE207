#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    int i,n,x;
    //insert a few elements
    v.push_back(6);
    v.push_back(10);
    v.push_back(2);
    v.push_back(8);
    v.push_back(3);
    // check the length of the vector
    cout<<"Length: " << v.size() <<endl;
    cout<<"Value at index 3 using at " << v.at(3) << endl;
    cout<<"Value at index 3 "<< v[3] <<endl;
    v.pop_back();
    v.pop_back();
    cout<<"Length: " << v.size() <<endl;
    v.clear();
    cout<<"Length: " << v.size() <<endl;
    return 0; 
}
