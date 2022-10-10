#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        
        if (left == nums.end() or nums[left-nums.begin()] != target) return {-1, -1};
        --right;
        int a = left - nums.begin();
        int b = right - nums.begin();
        return {a, b};
    }
};
