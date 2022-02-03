#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    queue<int> q;
    vector<vector<int> > V;
    
    void permutation(vector<int> v) {
        if (q.empty()) V.push_back(v);
        else {
            int num = q.size();
            for (int i = 0; i < num; i++) {
                int tmp = q.front();
                v.push_back(tmp);
                q.pop();
                permutation(v);
                v.erase(--v.end());
                q.push(tmp);
            }
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        for (auto i : nums) {
            q.push(i);
        }
        vector<int> v;
        permutation(v);
        
        return V;
    }
};