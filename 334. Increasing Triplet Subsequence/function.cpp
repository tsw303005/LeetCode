#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, right = INT_MAX;
        
        for (auto &i : nums) {
            if (left > i) left = i;
            else if (left < i and right > i) right = i;
            else if (i > right) return true;
        }
        
        return false;
    }
};
