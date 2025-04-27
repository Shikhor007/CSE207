#include <iostream>
#include <map>
#include <unordered_map> 
using namespace std;

int main(){
    map<string, int> map;
    map["apple"] = 1;
    map["banana"] = 2;
    map["orange"] = 3;
    cout << "map size: " << map.size() << endl;

    map.insert({{"grape", 4}, {"kiwi", 5}});//inserting multiple elements as pairs
    map.emplace("mango", 6);//inserting a single element as a pair

    for (auto p: map) {
        cout << p.first << ": " << p.second << endl;
    }
    //prints the output in sorted order of keys
    cout << "count of mango: " << map.count("mango") << endl;
    cout << "number of mango: " << map["mango"] << endl;
    map.erase("banana");//removes the key-value pair with key "banana"
    
    auto it = map.find("orange");//returns an iterator to the key-value pair with key "orange"
    if (it != map.end()) {
        cout << "found " << it->first << ": " << it->second << endl;
    } else {
        cout << it->first << " not found" << endl;
    }

    

    unordered_map<string, int> umap;
    umap["apple"] = 1;
    umap["banana"] = 2;
    umap["orange"] = 3;
    umap.insert({{"grape", 4}, {"kiwi", 5}});//inserting multiple elements as pairs
    umap.emplace("mango", 6);//inserting a single element as a pair
    cout << "unordered_map size: " << umap.size() << endl;
    for (auto p: umap) {
        cout << p.first << ": " << p.second << endl;
    }


    return 0;
}
