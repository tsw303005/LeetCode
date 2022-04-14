#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> s;
    
    void recur(int n, int left, string now) {
        if (n == 0 && left == 0) s.push_back(now);
        else {
            if (n > 0) recur(n - 1, left + 1, now + '(');
            if (left > 0) recur(n, left - 1, now + ')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        recur(n, 0, "");
        
        return s;
    }
};