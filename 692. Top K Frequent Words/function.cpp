#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        
        for (auto &word : words) {
            m[word]++;
        }
        
        auto comp = [&](const pair<string, int> &a, const pair<string, int> &b) {
            return (a.second > b.second) or (a.second == b.second and a.first < b.first);
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> q(comp);
        
        for (auto &word : m) {
            q.push({word.first, word.second});
            if (q.size() > k) q.pop();
        }
        
        vector<string> ans;
        
        while (!q.empty()) {
            ans.insert(ans.begin(), q.top().first);
            q.pop();
        }
        
        return ans;
    }
};
