#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        for (auto &str : paths) {
            parse(str);
        }
        
        vector<vector<string>> ans;
        for (auto &s : m) {
            if (s.second.size() == 1) continue;
            vector<string> re;

            for (auto &str : s.second) {
                re.emplace_back(str);
            }
            
            ans.emplace_back(re);
        }
        
        return ans;
    }
    
private:
    map<string, set<string>> m;

    void parse(const string& str) {
        vector<string> words;
        string text = str;
        string content;
        
        size_t pos = 0;
        string space_delimiter = " ";
        while ((pos = text.find(space_delimiter)) != string::npos) {
            words.emplace_back(text.substr(0, pos));
            text.erase(0, pos + space_delimiter.length());
        }
        words.emplace_back(text.substr(0, pos));
        
        
        for (int i = 1; i < words.size(); i++) {
            pos = words[i].find(".txt(");
            words[i].pop_back();
            content = words[i].substr(pos + 5, string::npos);
            
            m[content].insert(words[0] + "/" + words[i].substr(0, pos + 4));
        }
    }
};
