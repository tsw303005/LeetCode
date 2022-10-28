#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        
        string tmp;
        for (auto &str : strs) {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            m[tmp].emplace_back(str);
        }
        
        vector<vector<string>> ans;
        
        for (auto i = m.begin(); i != m.end(); i++) ans.emplace_back(i->second);
        
        return ans;
    }
};
