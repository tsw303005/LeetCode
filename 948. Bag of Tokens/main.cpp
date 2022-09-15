#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (tokens.size() == 0) return 0;
        else if (tokens.size() == 1) return (tokens[0] <= power) ? 1 : 0;

        sort(tokens.begin(), tokens.end());
        short int left, right;
        int left_power, ans;

        ans = 0;
        right = tokens.size() - 1;
        left_power = tokens[0];
        left = 1;
        
        while (left <= right && ans >= 0) {
            if (power >= left_power) left_power += tokens[left++], ans += 1;
            else power += tokens[right--], ans -= 1;
        }
        if (left_power <= power) ans += 1;
        return ans;
    }
};
