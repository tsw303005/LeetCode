#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k) return "0";
        
        string str = "";
        int len = num.length();
        int left = k;
        
        // 想法是從前往後開始看, 把 string 當作 stack, 現在在 string 裡面的數字代表是被挑選到的
        // 所以每次有新數字進來就跟 string 的 last num 去比較, 如果新數字比較小代表 last num, 可以被 new num 取代, 因此就 pop 掉,
        // 依照上面步驟重複直到 new num 放進 string 裡面
        for (int i = 0; i < len; i++) {
            char c = num[i];
            while (!str.empty() && left != 0) {
                if (str.back() > c) {
                    str.pop_back();
                    left -= 1;
                } else {
                    break;
                }
            }
            if (str != "" || c != '0') str.push_back(c);
        }
        // 檢查 left 如果還有剩，代表有數字還沒有刪完 => ex: num = "1234" k = 2, ans = "12"
        while (left-- > 0) str.pop_back();
        
        return str = (str.empty()) ? "0" : str;
    }
};