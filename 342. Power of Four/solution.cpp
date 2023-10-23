
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        unsigned long num = 1;
        
        if (n <= 0) return false;
        for (; num <= n; num <<= 2) {
            if (num == n) return true;
        }
        
        return false;
    }
};
