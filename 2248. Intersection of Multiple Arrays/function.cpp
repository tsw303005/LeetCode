#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        set<int> *s;
        set<int> *same;
        vector<int> ans;
        
        s = new set<int>;
        same = new set<int>;
        
        s->clear();
        same->clear();
        for (auto i : nums[0]) same->insert(i);
        
        for (int i = 1; i < nums.size(); i++) {
            for (auto j : nums[i]) {
                if (same->find(j) != same->end()) {
                    s->insert(j);
                }
            }
            swap(s, same);
            s->clear();
        }
        
        for (auto i : *same) {
            ans.push_back(i);
        }
        
        return ans;
    }
};