#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        
        sort(nums.begin(), nums.end());
        
        while (next_permutation(nums.begin(), nums.end())) ans.push_back(nums);
        ans.push_back(nums);
        return ans;
    }
};