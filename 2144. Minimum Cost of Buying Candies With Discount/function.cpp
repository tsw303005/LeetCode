#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int size = cost.size();
        int total = 0;
        for(int i = 1;i <= size;i++)
        {
            if(i % 3 != 0)
                total += cost[i-1];
        }
        return total;
    }
};