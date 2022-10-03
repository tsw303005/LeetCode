#include <vector>
#include <string>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int m = neededTime[0];

        for (int i = 1; i < colors.length(); i++) {
            if (colors[i] != colors[i-1]) m = neededTime[i];
            else ans += MIN(m, neededTime[i]), m = MAX(m, neededTime[i]);
        }

        return ans;
    }
};
