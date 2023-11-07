class Solution {
public:
    string removeStars(string s) {
        string ans;
        
        for (auto& letter : s) {
            if (letter == '*') ans.pop_back();
            else ans.push_back(letter);
        }
        
        return ans;
    }
};
