#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<short>& M, int color, int u) {
        M[u] = color;
        int flag = 1;
        int len = graph[u].size();
        for (int i = 0; i < len; i++) {
            if (M[graph[u][i]] == -1) flag = dfs(graph, M, !color, graph[u][i]);
            else if (M[graph[u][i]] == color) flag = 0;
            if (!flag) break;
        }
        return flag;
    }
    bool isBipartite(vector<vector<int> >& graph) {
        int n = graph.size();
        int ans = 1;
        vector<short> M(n, -1);
        for (int i = 0; i < n; i++) {
            if (M[i] == -1) ans = dfs(graph, M, 0, i);
            if (!ans) break;
        }
        return ans;
    }
};