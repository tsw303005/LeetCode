class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> m;
        unordered_set<int> s;
        unordered_set<int> stops;
        queue<int> q;

        int ans = 0;

        for (int i = 0; i < routes.size(); i++) {
            for (auto &stop : routes[i]) {
                m[stop].emplace_back(i);
            }
        }
        
        q.push(source);
        stops.insert(source);
        while (!q.empty()) {
            ans += 1;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int u = q.front();
                q.pop();
                if (u == target) return ans - 1;
                for (auto &j : m[u]) {
                    if (s.find(j) == s.end()) {
                        s.insert(j);
                        for (auto &k : routes[j]) {
                            if (stops.find(k) == stops.end()) q.push(k), stops.insert(k);
                        }
                    }
                }
            }
        }
        
        
        return -1;
    }
};
