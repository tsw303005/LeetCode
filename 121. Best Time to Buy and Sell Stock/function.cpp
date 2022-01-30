#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int small = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            if (small > prices[i]) small = prices[i];
            else ans = max(ans, prices[i] - small);
        }
        return ans;
    }
};