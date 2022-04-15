#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start = newInterval[0];
        int end = newInterval[1];
        int flag = 0;
        if (intervals.size() == 0) return vector<vector<int>>{newInterval};
        
        for (auto i : intervals) {
            if (start >= i[0] && start <= i[1] && end >= i[1]) start = i[0];
            else if (start <= i[0] && end >= i[0] && end <= i[1]) end = i[1];
            else if (start >= i[0] && end <= i[1]) return intervals;
            else if (end < i[0] && !flag) ans.push_back(vector<int>{start, end}), ans.push_back(i), flag = 1;
            else if (flag) ans.push_back(i);
            else if (start > i[1]) ans.push_back(i);
        }
        if (!flag) ans.push_back(vector<int>{start, end});
        
        return ans;
    }
};