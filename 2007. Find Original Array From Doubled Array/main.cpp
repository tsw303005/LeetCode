#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int v[100005] = {0};
        if (changed.size() % 2 != 0) {
            return vector<int>{};
        }
        
        for (auto &num : changed) {
            v[num] ++;
        }

        int num = 0;
        vector<int> original(changed.size() / 2);
        int run = 1;
        
        if (v[0] != 0 && v[0] % 2 != 0) return vector<int>{};
        else {
            num += v[0] / 2;
            for (int i = 0; i < v[0] / 2; i++) original[i] = 0;
        }
        for (; run <= 50000 && num < changed.size() / 2; run++) {
            if (v[run] && v[run*2] >= v[run]) {
                v[run * 2] -= v[run];
                for (; v[run] > 0; num++, v[run]--) original[num] = run;
            }
        }
        
        if (num == changed.size() / 2) return original;
        else return vector<int>{};
    }
};
