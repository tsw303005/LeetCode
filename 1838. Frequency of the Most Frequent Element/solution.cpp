#pragma GCC optimize("O3") 

const static auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return nullptr;
}();

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long total;
        int ans = 0;
        int window_size;
        int left = 0, right = 0;
        

        sort(nums.begin(), nums.end());
        total = nums[0];
        while (true) {
            window_size = right - left + 1;
            if (total + k >= 1LL * nums[right] * window_size) {
                ans = max(ans, window_size);
                if (right < nums.size() - 1) right++, total += nums[right]; 
            } else total -= nums[left], left++;
            
            if (right == nums.size() - 1 and right - left + 1 <= ans) break;
        }
        
        return ans;
    }
};
