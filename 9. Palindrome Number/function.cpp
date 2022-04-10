#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        string s = to_string(x);
        
        int right = s.length() - 1;
        int left = 0;
        
        while (left <= right && s[left] == s[right]) left++, right--;
        
        return (right < left);
    }
};