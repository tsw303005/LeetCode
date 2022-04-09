#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int ans = 0;
        int jump = 0;
        
        for (int i = 0; i < nums.size()-1; i++) {
            jump = max(jump, nums[i] + i);
            if (cur == i) {
                ans += 1;
                cur = jump;
            }
        }
        return ans;
    }
};