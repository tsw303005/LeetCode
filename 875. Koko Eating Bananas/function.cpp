#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto it = minmax_element(piles.begin(), piles.end());
        int left = min(1, *it.first);
        int right = *it.second;
        int len = piles.size();
        int ans = INT_MAX;
        long long int min_value, max_value, mid_value;
        
        if (len == h) return right;
        else if (len == 1) {
            double tmp = (double)piles[0] / (double)h;
            return ceil(tmp);
        }
        
        min_value = max_value = 0;
        for (int i = 0; i < len; i++) {
            double tmp = (double)piles[i]/(double)left;
            min_value += ceil(tmp);
            tmp = (double)piles[i] / (double)right;
            max_value += ceil(tmp);
        }

        if (min_value == max_value || min_value <= h) return left;
        ans = right;
        
        
        while (right-left >= 2) {
            int mid = (left+right)/2;
            mid_value = 0;
            for (int i = 0; i < len; i++) {
                double tmp = (double)piles[i] / (double)mid;
                mid_value += ceil(tmp);
            }

            if (mid_value <= h && mid < ans) {
                ans = mid;
                right = mid;
            } else {
                left = mid;
            }

        }
        
        return ans;
    }
};