#pragma GCC optimize("O3")

const static auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return nullptr;
}();

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        int biggest = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            biggest = (biggest > i + nums[i].size() - 1) ? biggest : i + nums[i].size() - 1;
        }
        
        vector<list<int>> record(biggest+1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                record[i+j].push_front(nums[i][j]);
            }
        }
        
        for (int i = 0; i <= biggest; i++) {
            auto &tmp = record[i];
            for (auto &num : tmp) ans.push_back(num);
        }
        
        
        return ans;
    }
};
