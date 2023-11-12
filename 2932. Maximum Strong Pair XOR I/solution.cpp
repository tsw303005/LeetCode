class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        using P = pair<int, int>;
        
        sort(nums.begin(), nums.end());
        vector<P> arr;
        for (int i = 0; i <= nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (abs(nums[j]-nums[i]) > nums[i]) break;
                else ans = max(nums[i] ^ nums[j], ans);
            }
        }
        
        return ans;
    }
};