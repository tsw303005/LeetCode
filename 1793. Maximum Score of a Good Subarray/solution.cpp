#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k];
        int small = nums[k];
        int left = k-1, right = k+1;
        
        // find smaller than nums[k]
        while (left >= 0 && nums[left] >= nums[k]) left--;
        while (right < nums.size() && nums[right] >= nums[k]) right++;
        
        ans = max(ans, small * (right - left - 1));
        
        while (left >= 0 || right < nums.size()) {
            if (left < 0) {
                for (; right < nums.size(); right++) {
                    if (nums[right] < small) small = nums[right];
                    ans = max(ans, small * (right+1));
                }
            } else if (right >= nums.size()) {
                for(; left >= 0; left--) {
                    if (nums[left] < small) small = nums[left];
                    ans = max(ans, small * (right - left));
                }
            } else if (nums[right] > nums[left]) {
                if (small > nums[right]) small = nums[right];
                right++;
                ans = max(ans, small * (right - left - 1));
            } else if (nums[left] >= nums[right]) {
                if (small > nums[left]) small = nums[left];
                left--;
                ans = max(ans, small * (right - left - 1));
            }
        }

        return ans;
    }
};
