#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        int left, right, mid, many, sum, ans;
        
        left = right = 0;
        
        for (auto p : nums) {
            if (p > left) left = p;
            right += p;
        }
        
        if (m == 1) return right;
        else if (m >= len) return left;
        
        while (left < right) {
            mid = (left + right) / 2;
            many = 1;
            sum = 0;
            for (int i = 0; i < len; i++) {
                sum += nums[i];
                if (sum > mid) {
                    sum = 0;
                    i -= 1;
                    many += 1;
                }
            }
            if (many <= m) {
                right = mid;
                ans = mid;
            } else {
                if (left == mid) break;
                left = mid;
            }
        }
        return ans;
    }
};