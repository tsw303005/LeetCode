#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int Max, Min, ans, tmp;
        Max = Min = ans = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            tmp = Max;
            Max = max(Max*nums[i], max(nums[i], Min*nums[i]));
            Min = min(tmp*nums[i], min(nums[i], Min*nums[i]));
            if (Max > ans) ans = Max;
        }
        return ans;
    }
};