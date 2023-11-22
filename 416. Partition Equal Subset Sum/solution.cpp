class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int target;
        bool dp[20005] = {false};
        
        for (auto &num : nums) total += num;
        if (total & 1) return false;
        else target = total / 2;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target - 1; j >= 1; j--) {
                if (dp[j]) dp[nums[i] + j] = true;
            }
            dp[nums[i]] = true;
            if (dp[target]) return true;
        }
        
        return false;
    }
};
