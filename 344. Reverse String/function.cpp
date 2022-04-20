#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left, right;
        
        if (s.size() % 2 == 0) {
            right = s.size() / 2;
            left = right - 1;
        } else left = right = s.size() / 2;
        
        while (left >= 0) {
            swap(s[left--], s[right++]);
        }
    }
};