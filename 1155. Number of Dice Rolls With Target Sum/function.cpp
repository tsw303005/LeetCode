#include <vector>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (target < n) return 0;
        vector<vector<int>> dp(target+1, vector<int>(n+1, -1));
        mod = 1000000007;

        dp[n][n] = 1;
        return recur(n, k, target, dp);
    }

    int recur(const int &n, const int &k, const int &target, vector<vector<int>> &dp) {
        if (target < n || n == 0) return 0;
        else if (n == 1 and target <= k) return 1;
        else if (dp[target][n] != -1) return dp[target][n];

        int result = 0;
        for (int i = 1; i <= k; i++) {
            result += recur(n-1, k, target-i, dp);
            result %= mod;
        }

        return dp[target][n] = result;
    }
private:
    int mod;
};
