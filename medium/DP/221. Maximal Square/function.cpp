#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char> >& matrix) {
      int row = matrix.size();
      int col = matrix[0].size();
      vector<vector<int> > M(row, vector<int>(col));
      int ans = 0;
      int tmp;
      
      for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
              if (i != 0 && j != 0 && matrix[i][j] == '1') {
                  tmp = min(M[i-1][j], M[i][j-1]);
                  tmp = min(tmp, M[i-1][j-1]);
                  M[i][j] = tmp+1;
              } else if (i == 0 || j == 0) {
                  M[i][j] = (matrix[i][j] == '0') ? 0 : 1;
              }
              ans = max(ans, M[i][j]*M[i][j]);
          }
      }
      return ans;
  }
};