#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int v[201][201];
    int recur(int left, int right) {
        if (left > right) return 0;
        else if (v[left][right] != 0x3f3f3f3f) return v[left][right];
        else if (left == right) return v[left][right] = 0;
        else {
            for (int i = left; i <= right; i++) {
                v[left][right] = min(v[left][right], i + max(recur(left, i-1), recur(i+1, right)));
            }
            return v[left][right];
        }
    }
    
    int getMoneyAmount(int n) {
        memset(v, 0x3f3f3f3f, sizeof(v));
        return recur(1, n);
    }
};