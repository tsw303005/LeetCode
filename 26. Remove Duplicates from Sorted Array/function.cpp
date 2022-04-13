#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int ans = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) nums[ans++] = nums[i];
        }
        
        return ans;
    }
};