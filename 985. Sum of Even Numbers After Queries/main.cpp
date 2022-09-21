#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        sum = 0;
        int mod;
        for (int i = 0; i < nums.size(); i ++) {
            if ((nums[i] % 2 + 2) % 2 == 0) {
                sum += nums[i];
                record[i] = true;
            } else {
                record[i] = false;
            }
        }
        
        for (auto &query : queries) {
            mod = (query[0] % 2 + 2) % 2; 

            if (record[query[1]] == false and mod == 1) {
                sum += nums[query[1]] + query[0];
                record[query[1]] = true; 
            } else if (record[query[1]] == true and mod == 1) {
                sum -= nums[query[1]];
                record[query[1]] = false;
            } else if (record[query[1]] == true and mod == 0) {
                sum += query[0];
            }
            nums[query[1]] += query[0];
            ans.emplace_back(sum);
        }
        
        return ans;
    }
private:
    bool record[10001];
    int sum;
    vector<int> ans;
};
