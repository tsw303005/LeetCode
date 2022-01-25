#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;
        
        for (i = nums.size()-2; i >= 0 && nums[i] >= nums[i+1]; i--);
        if (i < 0) return reverse(nums.begin(), nums.end());
        for (j = nums.size()-1; j > i && nums[j] <= nums[i]; j--);
        
        swap(nums[i], nums[j]);
        
        return reverse(nums.begin() + i + 1, nums.end());
    }
};