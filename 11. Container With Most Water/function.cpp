#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            area = max(min(height[left], height[right]) * (right - left), area);
            if (height[left] < height[right]) left += 1;
            else right -= 1;
        }
        return area;
    }
};