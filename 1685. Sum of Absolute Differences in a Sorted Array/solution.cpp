const static auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return nullptr;
}();

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans(nums.size());
        int total = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }
        
        int left, right, self;
        
        #pragma unroll(5)
        for (int i = 0; i < nums.size(); i++) {
            left = nums[i];
            if (i == 0) self = nums[0];
            else self = nums[i] - nums[i-1];

            if (i == nums.size() - 1) right = 0;
            else right = nums[nums.size() - 1] - nums[i];
            ans[i] = (self * (i + 1) - left) + (right - (nums.size() - 1 - i) * self);
        }
        
        return ans;
    }
};
