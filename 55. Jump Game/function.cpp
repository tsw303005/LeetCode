#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size() - 1;
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] + i >= target) {
                target = i;
            }
        }
        if (target == 0) return true;
        else return false;
    }
};