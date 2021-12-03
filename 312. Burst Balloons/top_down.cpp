#include <iostream>
#include <string.h>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > M;
  int recur(int left, int right, vector<int>& nums) {
    if (left > right) return 0;
    else if (left == right) return M[left][right] = nums[left] * nums[left-1] * nums[left+1];
    else if (M[left][right] != INT_MIN) return M[left][right];
    else {
      int result = INT_MIN;
      for (int i = left; i <= right; i++) {
        int tmp = nums[left-1] * nums[right+1] * nums[i];
        result = max(tmp+recur(left, i-1, nums)+recur(i+1, right, nums), result);
      }
      return M[left][right] = result;
    }
  }
  
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1, 1);
    nums.push_back(1);
    M.resize(n+1, vector<int>(n+1, INT_MIN));
    return recur(1, n, nums);
  }
};