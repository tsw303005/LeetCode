#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2; 
        int a, b, tmp;
        a = 1;
        b = 2;
        
        for (int i = 3; i <= n; i++) {
            tmp = a + b;
            a = b;
            b = tmp;
        }
        
        return b;
    }
};