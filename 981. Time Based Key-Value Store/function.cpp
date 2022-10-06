#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
public:
    struct storeValue {
        int timeStamp;
        string value;
        
        storeValue() : timeStamp(0), value("") {}
        storeValue(int x, string str) : timeStamp(x), value(str) {}
    };

    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";

        auto result = lower_bound(m[key].begin(), m[key].end(), timestamp, [](const storeValue& store, int timestamp) {
           return store.timeStamp < timestamp; 
        });
        
        if (result == m[key].end()) return m[key][m[key].size()-1].value;
        else if (result == m[key].begin() and result->timeStamp > timestamp) return "";
        else if (result->timeStamp > timestamp) return m[key][result-m[key].begin()-1].value;
        else return result->value;
    }
    
private:
    unordered_map<string, vector<storeValue>> m;
};
