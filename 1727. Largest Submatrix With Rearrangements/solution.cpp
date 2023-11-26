const static auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return nullptr;
}();

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0, run;
        for (int i = 0; i < matrix[0].size(); i++) {
            run = 0;
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[j][i] == 1) run += 1;
                else run = 0;
                matrix[j][i] = run;
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            sort(matrix[i].begin(), matrix[i].end(), [&](const int a, const int b) {
               return a > b;
            });

            for (int j = 0; j < matrix[0].size() and matrix[i][j] != 0; j++) {
                ans = max(ans, (j + 1) * matrix[i][j]);
            }
        }
        
        return ans;
    }
};
