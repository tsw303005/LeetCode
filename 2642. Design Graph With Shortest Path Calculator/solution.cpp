const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Graph {
private:
    using P = pair<int, int>;
    vector<vector<P>> graph;
    const int infinity = 0x3f3f3f3f;
    int size;
    
    int dijkstra(int start, int end) {
        vector<int> dist(this->size, this->infinity);
        priority_queue<P, vector<P>, greater<P>> pq;
        
        dist[start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();
            
            if (u == end) return du;
            if (dist[u] < du) continue;
            
            for (auto [v, dv] : this->graph[u]) {
                if (dist[v] > dist[u] + dv) {
                    dist[v] = dist[u] + dv;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return -1;
    }
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->size = n;
        this->graph = vector<vector<P>>(this->size);
        
        for (auto& edge : edges) {
            this->graph[edge[0]].emplace_back(P{edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        this->graph[edge[0]].emplace_back(P{edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }
};
