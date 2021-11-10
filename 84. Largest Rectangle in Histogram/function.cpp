#include <iostream>
#include <deque>
#include <vector>
#include <limits.h>

// 這題想法比 132 pattern 簡單一點, 就是用 stack 找出每個數字的左邊界跟右邊界, 然後跟數字相乘, 最後跟當前找到的答案判斷有沒有需要更新

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        deque <int> S;
        int ans = INT_MIN;
        int len = heights.size();
        int now_num, tmp;
        int record[len+1];
        int top_value;
        
        for (int i = len-1; i >= 0; i--) {
            now_num = heights[i];
            while (!S.empty()) {
                top_value = S.back();
                if (heights[top_value] > now_num) {
                    tmp = (record[top_value] - i) * heights[top_value];
                    if (ans < tmp) ans = tmp;
                    S.pop_back();
                } else {
                    break;
                }
            }
            if (S.empty()) {
                record[i] = len-1;
            } else {
                record[i] = S.back() - 1;
            }
            S.push_back(i);
        }
        while (!S.empty()) {
            top_value = S.back();
            tmp = (record[top_value]+1) * heights[top_value];
            if (ans < tmp) ans = tmp;
            
            S.pop_back();
        }
        
        return ans;
    }    
};