#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        ans = 0;
        sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b)  { return (a[0] != b[0]) ? a[0] < b[0] : a[1] > b[1]; });
        
        mx = properties[properties.size()-1][1];
        for (int i = properties.size() - 2; i >= 0; i--) {
            if (properties[i][1] < mx) ans += 1;
            mx = max(mx, properties[i][1]);
        }
        
        return ans;
    }
private:
    int ans;
    int mx;
};
