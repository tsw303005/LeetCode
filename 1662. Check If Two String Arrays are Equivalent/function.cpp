#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string x;
        
        for (auto &str : word1) x += str;
        int now = 0;
        
        for (auto & str : word2) {
            if (x.compare(now, str.length(), str) != 0) return false;
            now += str.length();
        }
        if (now != x.length()) return false;
        
        return true;
    }
};
