#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        m = multipliers.size();
        n = nums.size();
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        return recur(0, 0, nums, multipliers);
    }
private:
    int dp[1000][1000];
    int m, n;
    int recur(int l, int i, vector<int>& nums, vector<int>& multipliers) {
        if (i == m) return 0;
        if (dp[l][i] != 0x3f3f3f3f) return dp[l][i];
        
        int left = recur(l+1, i+1, nums, multipliers) + nums[l] * multipliers[i];
        int right = recur(l, i+1, nums, multipliers) + nums[n-1-(i-l)] * multipliers[i];
        
        return dp[l][i] = max(left, right);
    }
};
