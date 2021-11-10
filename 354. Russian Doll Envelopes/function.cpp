#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
    }
    
    static bool compare2(const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first == b.first) ? a.second < b.second : a.first < b.first;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        list <pair<int, int> > ans;
        int num = 0;
        
        sort(envelopes.begin(), envelopes.end(), compare);
        
        for (auto i : envelopes) {
            pair <int, int> tmp;
            tmp.first = i[0];
            tmp.first = i[1];
            auto it = lower_bound(ans.begin(), ans.end(), tmp, compare2);
            if (it == ans.end()) {
                ans.emplace_back(tmp);
                num += 1;
            } else {
                *it = tmp;
            }
        }
        
        return num;
    }
};