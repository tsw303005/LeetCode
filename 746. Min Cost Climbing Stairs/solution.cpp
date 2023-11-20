class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int top = cost.size();
        
        // used for record every step with min cost
        vector<int> record(cost.size() + 2, 0x3f3f3f3f);
        record[0] = record[1] = 0;
        
        for (int i = 0; i < cost.size(); i++) {
            record[i + 1] = min(record[i + 1], record[i] + cost[i]);
            record[i + 2] = min(record[i + 2], record[i] + cost[i]);
        }
        
        return min(record[cost.size()], record[cost.size() + 1]);
    }
};
