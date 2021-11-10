#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool ans;
    unordered_map <int, int> M;
    void find(int now, int k, int terminal, vector<vector<bool>>& record, vector<int>& stones) {
        if (now == terminal || ans == true) {
            ans = true;
            return ;
        }
        else if (record[now][k]) return ;
        record[now][k] = true;
        for (int i = max(k-1, 1); i < k+2; i++) {
            if (M.find(stones[now]+i) != M.end()) find(M[stones[now]+i], i, terminal, record, stones);
        }
    }
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<vector<bool>> record(stones.size(), vector<bool>(len + 5,  false));
        for (int i = 0; i < len; i++) {
            M[stones[i]] = i;
        }
        ans = false;
        if (stones[1] != 1) return ans;
        else if (stones.size() == 1) return true;
        else find(1, 1, stones.size()-1, record, stones);
        return ans;
    }
};