class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell = 0;
        int buy = -1 * prices[0];
        int tmp;
        
        // sell is used for biggest profit when selling i
        // buy is used for biggest profit when buying i
        // interate to find the answer
        for (int i = 1; i < prices.size(); i++) {
            tmp = buy;
            buy = max(sell - prices[i], buy);
            sell = max(prices[i] + tmp - fee, sell);
        }
            
            
        return sell;
    }
};
