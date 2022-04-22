#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans, left, right, lower, tmp;
        
        lower = left = ans = 0;
        right = height.size() - 1;
        
        while (left < right) {
            tmp = (height[left] < height[right] ? height[left++] : height[right--]);
            lower = (lower < tmp) ? tmp : lower;
            ans += lower - tmp;
        }
        
        return ans;
    }
};