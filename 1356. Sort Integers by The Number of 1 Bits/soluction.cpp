#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;

    vector<int> sortByBits(vector<int>& arr) {
        vector<P> v;
        for (auto &i : arr) {
            int bit = 0;
            int num = i;
            while (num) {
                bit += (num & 1);
                num >>= 1;
            }
            
            v.push_back({bit, i});
        }
        
        sort(v.begin(), v.end(), [](P a, P b) {
            if (a.first != b.first) return a.first < b.first;
            else return a.second < b.second;
        });
        
        for (int i = 0; i < v.size(); i++) {
            arr[i] = v[i].second;
        }
        
        return arr;
    }
};
