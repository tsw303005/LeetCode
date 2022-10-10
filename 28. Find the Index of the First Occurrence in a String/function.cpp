#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int left, right;
        
        for (left = 0, right = 0; left < haystack.length(); ++left, right = 0) {
            while (right < needle.length() and haystack[left+right] == needle[right]) right++;
            if (right == needle.length()) return left;
        }
        
        return -1;
    }
};
