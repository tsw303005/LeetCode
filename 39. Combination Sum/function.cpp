#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());

        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        recur(target, 0, tmp, candidates);
        
        
        return result;
    }
    
    void recur(int target, int index, vector<int>& v, vector<int>& candidates) {
        if (target == 0) {
            result.push_back(v);
            return;
        }

        while (index < candidates.size() and candidates[index] <= target) {
            v.push_back(candidates[index]);
            recur(target-candidates[index], index, v, candidates);
            index++;
            v.pop_back();
        }
    }
};
