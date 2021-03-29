#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        vector<vector<int>> G(numCourses);
        vector<int> record(numCourses, 0);
        vector<int> ans;
        queue<int> q;
        int now;
        for (auto i : prerequisites) {
            G[i[1]].push_back(i[0]);
            record[i[0]] += 1;
        }
        for (int i = 0; i < numCourses; i++) {
            if (record[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            now = q.front();
            q.pop();
            ans.push_back(now);
            for (auto i : G[now]) {
                record[i] -= 1;
                if (record[i] == 0) q.push(i);
            }
        }
        if (ans.size() != numCourses) ans.clear();
        return ans;
    }
};