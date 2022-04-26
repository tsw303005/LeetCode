#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        int i = 0;
        int connected = 0;
        vector<bool> visited(n);
        priority_queue<pair<int, int>> q;
        
        while (++connected < n) {
            visited[i] = true;
            
            for (int j = 0; j < n; j++) {
                if (!visited[j])
                    q.push({-1 * (abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])), j});
            }
            
            while (visited[q.top().second])
                q.pop();
            ans -= q.top().first;
            i = q.top().second;
            q.pop();
        }
        
        return ans;
    }
};
