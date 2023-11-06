class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> m(values.size());
        using P = pair<long long, long long>;
        
        for (auto& edge : edges) {
            m[edge[0]].emplace_back(edge[1]);
            m[edge[1]].emplace_back(edge[0]);
        }
        
        function<P(int, int)> dfs = [&](int cur, int parent) -> P {
            long long M = 0;
            long long total = values[cur];
            bool flag = false;
            
            for (auto &neighbor : m[cur]) {
                if (neighbor != parent) {
                    auto result = dfs(neighbor, cur);
                    M += result.second;
                    total += result.first;
                    flag = true;
                }
            }
            if (flag) {
                M = (total - values[cur] > M + values[cur]) ? total - values[cur] : M + values[cur];
            }

            return {total, M};
        };
        
        return dfs(0, -1).second;
    }
};