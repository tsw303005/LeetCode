class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> v(n);
        int run;
        int ans = -1;
        
        for (int i = 0; i < n; i++) v[i] = i;
        
        function<int(int)> djs = [&](int r) {
            if (v[r] != r) return v[r] = djs(v[r]);
            else return v[r];
        };
        
        for (auto &e : edges) {
            v[e[1]] = e[0];
            djs(v[1]);
        }
        
        for (int i = 0; i < n; i++) {
            if (v[i] == i and ans == -1) ans = i;
            else if (v[i] == i and ans != -1) return -1;
        }
            
        return ans;
    }
};
