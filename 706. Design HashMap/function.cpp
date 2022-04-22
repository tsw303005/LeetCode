#include <iostream>
#include <unordered_map>

using namespace std;

class MyHashMap {
private:
    vector<unordered_map<int, int>> v;
    int prime;
public:
    MyHashMap() {
        v.resize(1007);
        prime = 1007;
    }
    
    void put(int key, int value) {
        int index = key % prime;
        
        v[index][key] = value;
    }
    
    int get(int key) {
        int index = key % prime;
        
        if (v[index].find(key) != v[index].end()) return v[index][key];
        return -1;
    }
    
    void remove(int key) {
        int index = key % prime;
        
        auto f = v[index].find(key);
        if (f != v[index].end()) v[index].erase(f);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
