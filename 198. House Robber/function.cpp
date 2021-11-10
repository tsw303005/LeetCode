#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() >= 2) nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
        return nums[nums.size()-1];
    }
};