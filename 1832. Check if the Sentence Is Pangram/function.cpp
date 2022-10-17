#include <string>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int result = 0;
        
        for (auto &c : sentence) {
            result |= (1 << (c - 'a'));
            if (result == 67108863) return true;
        }
        
        return false;
    }
};
