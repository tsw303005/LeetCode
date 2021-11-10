#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int recur(int target, vector<int>& nums, vector<int>& record) {
        if (target == 0) return 1;
        if (record[target] != -1) return record[target];
        record[target] = 0;
        for (auto i : nums) {
            if (i <= target) record[target] += recur(target-i, nums, record);
        }
        return record[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> record(1001, -1);
        return recur(target, nums, record);
    }
};