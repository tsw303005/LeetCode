class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> m;
        
        if (adjacentPairs.size() == 1) return {adjacentPairs[0][0], adjacentPairs[0][1]};
        for (auto& pair : adjacentPairs) {
            m[pair[0]].push_back(pair[1]);
            m[pair[1]].push_back(pair[0]);
        }
        
        int cur, prev = 100001, tmp;
        vector<int> ans;
        for (auto i = m.begin(); i != m.end(); i++) {
            if (i->second.size() == 1) {
                cur = i->first;
                break;
            }
        }

        for (; ans.size() < adjacentPairs.size(); prev = cur, cur = tmp) {
            ans.push_back(cur);
            if (m[cur][0] != prev) tmp = m[cur][0];
            else tmp = m[cur][1];
        }
        ans.push_back(tmp);
        
        return ans;
    }
};