#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unsigned long a = 0;
        unsigned long total = (1 + nums.size()) * nums.size() / 2;
        unsigned long x;
        unsigned long y;
        unordered_set<int> s;
        
        for (auto &i : nums) {
            a += i;
            if (s.find(i) != s.end()) x = i;
            else s.insert(i);
        }
        y = total - a + x;

        return {(int)x, (int)y};
    }
};
