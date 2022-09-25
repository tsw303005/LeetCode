#include <deque>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        size = k;
        q.clear();
    }
    
    bool enQueue(int value) {
        if (!isFull()) q.push_back(value);
        else return false;
        return true;
    }
    
    bool deQueue() {
        if (!isEmpty()) q.pop_front();
        else return false;
        return true;
    }
    
    int Front() {
        if (!isEmpty()) return q.front();
        else return -1;
    }
    
    int Rear() {
        if (!isEmpty()) return q.back();
        else return -1;
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return q.size() == size;
    }
private:
    deque<int> q;
    int size;
};
