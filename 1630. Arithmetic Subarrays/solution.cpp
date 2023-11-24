class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int Max, Min, count, d, total, s;
        
        for (int i = 0; i < l.size(); i++) {
            Max = -1 * 1e5;
            Min = 1e5;
            total = 0;
            count = r[i] - l[i] + 1;
            for (int j = l[i]; j <= r[i]; j++) {
                Max = (Max > nums[j]) ? Max : nums[j];
                Min = (Min < nums[j]) ? Min : nums[j];
                total += nums[j];
            }
            
            d = (Max - Min) / (count - 1);
            s = count * (2 * Min + (count - 1) * d) / 2;
            
            if (s != total) {
                ans.push_back(false);
                continue;
            } else if (d == 0) {
                ans.push_back(true);
                continue;
            }
            unordered_set<int> s;
            for (int j = l[i]; j <= r[i]; j++) {
                if ((Max - nums[j]) % d != 0 || s.find(nums[j]) != s.end()) {
                    ans.push_back(false);
                    break;
                } else if (j == r[i]) {
                    ans.push_back(true);
                }
                s.insert(nums[j]);
            }
        }
        
        return ans;
    }
};
