#include <iostream>
#include <stack>
#include <vector>

// 主要是 stack 配合一個 array 去紀錄
// 想法上是遍歷所有的 num, 每次走到 i, 就要找到所有 subset 中到 i 的解加上去
// 如果有 j 在 i 的前面比 i 還小, 我們只需要從陣列中拿出 j 存得值跟 j+1 ~ i 之間的值加上去就是答案


using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0;
        int len = arr.size();
        int record[30005];
        int now_num, com_num;
        int add;
        stack <int> S;

        for (int i = 0; i < len; i++) {
            now_num = arr[i];
            while (!S.empty() && now_num <= arr[S.top()]) {
                S.pop();
            }
            if (S.empty()) {
                add = now_num * (i+1);
                add %= 1000000007;
                ans += add;
                record[i] = add;
            } else {
                add = (i-S.top()) * now_num;
                add += record[S.top()];
                add %= 1000000007;
                ans += add;
                record[i] = add;
            }
            S.push(i);
            ans %= 1000000007;
        }
        return ans;
    }
};