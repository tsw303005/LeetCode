#include <iostream>

using namespace std;

class Solution {
public:
    bool recur(string s, int left, int right, int used) {
        while (left < right and s[left] == s[right]) left++, right--;
        if (left >= right) return true;
        else if (!used) return false;
        else return recur(s, left+1, right, 0) || recur(s, left, right-1, 0);
    }
    
    bool validPalindrome(string s) {
        return recur(s, 0, s.length()-1, 1);
    }
};
