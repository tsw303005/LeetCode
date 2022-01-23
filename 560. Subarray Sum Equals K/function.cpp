#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;       
        int now = 0;
        int ans = 0;
        
        for (auto i : nums) {
            m[now] += 1;
            now += i;
            ans += m[now - k];
        }
        return ans;
    }
};