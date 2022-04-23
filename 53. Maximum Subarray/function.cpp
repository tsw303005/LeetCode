#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {        
        int ans = nums[0];
        int now = 0;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            if (now + nums[i] < 0) now = nums[i];
            else now += nums[i];
            ans = (now > ans) ? now : ans;
            if (now < 0) now = 0;
        }
        
        return ans;
    }
};
