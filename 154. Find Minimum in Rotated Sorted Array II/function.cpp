#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int recur(vector<int>& nums, int left, int right) {
        int mid;
        if (left >= right-1) {
            return min(nums[left], nums[right]);
        }
        
        mid = (left + right) / 2;
        if (nums[left] < nums[right]) {
            return nums[left];
        } else if (nums[mid] < nums[left]) {
            return recur(nums, left, mid);
        } else if (nums[mid] > nums[right]) {
            return recur(nums, mid, right);
        }
        return min(recur(nums, left, mid), recur(nums, mid+1, right));
    }
    
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left, right, mid;
        
        left = 0;
        right = nums.size()-1;
    
        return recur(nums, left, right);
    }
};