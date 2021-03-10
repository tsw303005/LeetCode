#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int put_big[10005], len, now_num, top_num;
        stack <int> S;
        
        len = nums2.size();
        put_big[nums2[len-1]] = -1;
        S.push(nums2[len-1]);
        for (int i = len-2; i >= 0; i--) {
            now_num = nums2[i];
            put_big[now_num] = -1;
            while (!S.empty()) {
                top_num = S.top();
                if (top_num > now_num) {
                    put_big[now_num] = top_num;
                    break;
                } else {
                    S.pop();
                }
            }
            S.push(now_num);
        }
        vector<int> ans;
        len = nums1.size();
        for (int i = 0; i < len; i++) {
            ans.push_back(put_big[nums1[i]]);
        }
        return ans;
    }
};