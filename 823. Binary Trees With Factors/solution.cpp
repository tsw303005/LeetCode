#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

#define MODULO 1000000007

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, unsigned long> m;
        int square_root;
        int ans = 0;
        
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]] = 0;
            square_root = sqrt(arr[i]);
            for (int j = 0; j < i && arr[j] <= square_root; j++) {
                if (arr[i] % arr[j] == 0) {
                    auto f = m.find(arr[i]/arr[j]);
                    if (f != m.end()) {
                        if (f->first == arr[j]) m[arr[i]] += m[arr[j]] * f->second;
                        else m[arr[i]] += (m[arr[j]] * f->second * 2);
                        m[arr[i]] %= MODULO;
                    }
                }
            }
            m[arr[i]] += 1;
            m[arr[i]] %= MODULO;
            ans += m[arr[i]];
            ans %= MODULO;
         }
        
        return ans;
    }
};
