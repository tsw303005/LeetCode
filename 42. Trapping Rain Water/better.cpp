#include <iostream>
#include <vector>

/*
    you can think this problem has left, and right bound,
    every time we compare heigh[left] and height[right] to find which is lower (tmp),
    the lower one will compare to the lower value now,
    if tmp < lower means that the tmp is trapping and the ans will be added (lower - tmp),
    if tmp > loewr means that the new bound is found, so the lower value will changed to the tmp,
    continue to do this until the left >= right,

    so the idea is that we need to find the left and right bound if we want to know if index i is trapping,
    we have to find if there are left and right value beigger than index[i],
    the we can get the ans
*/

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