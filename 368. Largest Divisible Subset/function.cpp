#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        vector<int> pre(nums.size()+1, -1);
        int ans = 1;
        int s = 0;

        vector<int> record(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && record[i] <= record[j]) {
                    record[i] = record[j] + 1;
                    pre[i] = j;
                    if (record[i] > ans) {
                        s = i;
                        ans = record[i];
                    }
                }
            }
        }
        while (pre[s] != -1) {
            result.push_back(nums[s]);
            s = pre[s];
        }
        result.push_back(nums[s]);
        return result;
    }
};