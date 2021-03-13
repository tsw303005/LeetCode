#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>

using namespace std;

// 這題想法是用一個 stack 去紀錄
// record 這個 array 是用來記錄每個在 element i 之前最小的元素
// 每次新的 element i 進來就跟 stack 的元素開始去比較, 直到遇到比 i 還大的元素 j 就暫停
// 然後檢查 record[j] 看看 i 有沒有比 record[j] 紀錄的元素還要大, 有的話代表成立
// 所以會有一個 min 去紀錄現在到 element i 之前的最小的元素, 每次都會紀錄 record[i] 之前的 min value
// 這樣做法會對的原因是因為, 我們陣列是由前往後, 所以每當 element i 在 stack 找到一個元素 j, i 必定比 j 還要後面, 而 record[j] 紀錄的數字也一定比 j 前面, 這樣就符合題目敘述

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack <int> S;
        int len = nums.size();
        int record[10005];
        int now_num, com_num, min;
        
        
        S.push(0);
        min = nums[0];
        record[0] = INT_MAX;
        for (int i = 1; i < len; i++) {
            now_num = nums[i];
            if (min > now_num) {
                min = now_num;
            }
            while (!S.empty() && nums[S.top()] <= now_num) { // 考慮 [-2, 1, 1] 這個情況的話, 不加等於會錯
                S.pop();
            }
            if (S.empty()) {
                record[i] = min;
            } else {
                if (record[S.top()] < now_num) {
                    return true;
                } else {
                    record[i] = min;
                }
            }
            S.push(i);
        }
        return false;
    }
};