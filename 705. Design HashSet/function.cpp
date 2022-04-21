#include <iostream>
#include <list>
#include <vector>

using namespace std;

class MyHashSet {
private:
    vector<list<int>> v;
    int prime;
public:
    
    MyHashSet() {
        prime = 1007;
        v.resize(prime);
    }
    
    void add(int key) {
        if (contains(key)) return;
        v[key % prime].push_back(key);
    }
    
    void remove(int key) {
        int index = key % prime;
        if (!contains(key)) return;
        v[index].erase(find(v[index].begin(), v[index].end(), key));
    }
    
    bool contains(int key) {
        int index = key % prime;
        return (find(v[index].begin(), v[index].end(), key) != v[index].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */