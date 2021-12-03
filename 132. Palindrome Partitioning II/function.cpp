#include <iostream>

using namespace std;

class Solution {
public:
  bool record[2001][2001] = {false};
  int dp[2001];
  void palindrome(string s) {
    int left, right, a, b;
    left = right = 0;
    while (right != s.length()) {
      a = left;
      b = right;
      while (a >= 0 && b < s.length() && s[a] == s[b]) {
        record[a][b] = true;
        a--;
        b++;
      }
      if (left == right) right++;
      else left++;
    }
  }
  
  int find(int n) {
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        if (record[j][i] == true) {
          if (j == 0) dp[i] = 0;
          else dp[i] = min(dp[i], 1 + dp[j-1]);
        }
      }
    }
    return dp[n];
  }
  
  int minCut(string s) {
    memset(dp, 0x3f3f3f3f3f, sizeof(dp));
    palindrome(s);
    return find(s.length()-1);
  }
};