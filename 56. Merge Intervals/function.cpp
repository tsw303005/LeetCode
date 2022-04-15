#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > ans;
        if (not intervals.size()) return ans;
        
        int start, end;
        
        sort(intervals.begin(), intervals.end());
        
        start = intervals[0][0];
        end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (end >= intervals[i][0]) end = max(intervals[i][1], end);
            else {
                ans.emplace_back(vector<int>{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.emplace_back(vector<int>{start, end});
        
        return ans;
    }
};