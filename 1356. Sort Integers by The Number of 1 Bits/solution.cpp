#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bit_a = __builtin_popcount(a);
            int bit_b = __builtin_popcount(b);
            
            if (bit_a != bit_b) return bit_a < bit_b;
            else return a < b;
        });
        
        return arr;
    }
};