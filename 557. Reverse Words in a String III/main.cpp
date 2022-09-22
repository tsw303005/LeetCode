#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i, pos, lastPos;
        
        for (i = lastPos = pos = 0; i < s.length(); i++) {
            if (s[i + 1] == ' ' or i == s.length() - 1) {
                pos = i;
                while (pos > lastPos) swap(s[pos], s[lastPos]), pos--, lastPos++;
                lastPos = i + 2;
            }
        }
        
        return s;
    }
};
