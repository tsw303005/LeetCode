class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        
        for (auto &i : left) {
            if (i > ans) ans = i;
        }
        
        for (auto &i : right) {
            if (n-i > ans) ans = n-i;
        }
        
        return ans;
    }
};
