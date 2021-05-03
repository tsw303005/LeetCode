#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int> >& triangle) {
      int ans;
      int len = triangle.size()-1;
      for (int i = 1; i < triangle.size(); i++) {
          for (int j = 0; j < triangle[i].size(); j++) {
              if (j == 0) triangle[i][j] += triangle[i-1][j];
              else if (j == triangle[i].size()-1) triangle[i][j] += triangle[i-1][j-1];
              else triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
          }
      }
      ans = *min_element(triangle[len].begin(), triangle[len].end());
      return ans;
  }
};