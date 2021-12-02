#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> record(nums.size(), 1);
        vector<int> pre(nums.size(), -1);
        vector<int> re;
        int ans = 0;
        
        for (int i = 1; i < nums.size(); i++) {
          for (int j = i-1; j >= 0; j--) {
            if (nums[i] % nums[j] == 0 && record[j] + 1 > record[i]) {
                record[i] = record[j] + 1;
                pre[i] = j;
                ans = (record[ans] < record[i]) ? i : ans;
            }
          }
        }
        
        while (ans != -1) {
            re.insert(re.begin(), nums[ans]);
            ans = pre[ans];
        }
        return re;
    }
};