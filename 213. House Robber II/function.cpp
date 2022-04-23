#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:  
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int res, a, b, ans;
        
        res = a = b = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            res = max(a, b + nums[i]);
            b = a;
            a = res;
        }
        ans = res;
        
        res = a = b = 0;
        for (int i = 1; i < nums.size(); i++) {
            res = max(a, b + nums[i]);
            b = a;
            a = res;
        }
        
        return max(res, ans);
    }
};
