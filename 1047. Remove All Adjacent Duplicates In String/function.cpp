#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        
        for (auto &c : s) {
            if (ans.size() > 0 and ans[ans.size()-1] == c) ans.pop_back();
            else ans += c;
        }
        
        return ans;
    }
};
