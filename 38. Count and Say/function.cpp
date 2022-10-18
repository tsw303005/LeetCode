#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        else if (m.find(n) != m.end()) return m[n];
        
        m[n] = convert(countAndSay(n-1));
        return m[n];
    }
    
private:
    unordered_map<int, string> m;
    
    string convert(const string &s) {
        string result = "";
        
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) count++;
            else {
                result += to_string(count) + s[i-1];
                count = 1;
            }
        }
        
        result += to_string(count) + s[s.length()-1];
        
        return result;
    }
};
