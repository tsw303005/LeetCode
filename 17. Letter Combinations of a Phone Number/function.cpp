#include <iostream>
#include <vector>

using namespace std

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        const vector<string> number = {
            "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
        if (digits.length()) ans.push_back("");
        
        for (auto digit : digits) {
            vector<string> tmp;
            for (auto i : ans) {
                for (auto letter: number[digit - '2']) {
                    tmp.push_back(i + letter);
                }
            }
            ans.swap(tmp);
        }
        
        return ans;
    }
};
