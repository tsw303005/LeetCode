#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        m.rehash(50);
        int ans = 0;
        int now = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end() && m[s[i]] >= now) now = m[s[i]] + 1;
            m[s[i]] = i;
            
            ans = max(ans, i - now + 1);
        }
        
        return ans;
    }
};