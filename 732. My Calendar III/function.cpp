#include <map>

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start] += 1;
        m[end] -= 1;
        
        int maxInt = 0, curInt = 0;
        
        for (auto &i : m) {
            curInt += i.second;
            maxInt = max(curInt, maxInt);
        }
        
        return maxInt;
    }
    
private:
    map<int, int> m;
};
