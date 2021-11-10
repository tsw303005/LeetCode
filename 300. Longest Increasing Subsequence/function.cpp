#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> V;
        for (auto p : nums) {
            auto index = lower_bound(V.begin(), V.end(), p);
            if (index == V.end()) V.push_back(p);
            else *index = p;
        }
        return V.size();
    }
};