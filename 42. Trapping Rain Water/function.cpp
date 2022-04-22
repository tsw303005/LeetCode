#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int ans = 0;
        int middle;
        stack<pair<int, int>> s;
        
        for (int i = 0; i < len; i++) {
            middle = 0;
            while (!s.empty()) {
                auto top = s.top();
                if (top.first > height[i]) {
                    ans += (i - top.second - 1) * (height[i] - middle);
                    break;
                } else {
                    s.pop();
                    ans += (i - top.second - 1) * (top.first - middle);
                    middle = top.first;
                }
            }
            s.push({height[i], i});
        }
        return ans;
    }
};