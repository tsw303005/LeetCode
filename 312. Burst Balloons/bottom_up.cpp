#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    int dp[n+2][n+2];
    int arr[n+2];
    arr[0] = arr[n+1] = 1;
    for (int i = 1; i < n + 1; i++) arr[i] = nums[i-1];
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i < n + 2; i++) {
      for (int j = 0; j + i < n + 2; j++) {
        for (int k = j + 1; k < j + i; k++) {
          dp[j][j+i] = max(dp[j][j+i], dp[j][k] + dp[k][i+j] + arr[j] * arr[k] * arr[j+i]);
        }
      }
    }
    return dp[0][n+1];
  }
};