#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        ans = 0;
        int tmp;
        vector<int> con;
        for (auto &str : arr) {
            tmp = convert(str);
            if (tmp != 0) con.push_back(tmp);
        }
        
        for (int i = 0; i < con.size(); i++) {
            recur(con, i, con[i]);
        }
        return ans;
    }
private:
    int ans;
    int convert(const string &str) {
        int n;
        int result = 0;
        
        for (auto &c : str) {
            n = (1 << (c - 'a' + 1));
            if ((result & n) != 0) return 0;
            result |= n;
        }
        return result;
    }
    
    void recur(vector<int> &con, int now, int num) {
        int a;
        ans = max(ans, conLen(num));
        for (int i = now + 1; i < con.size(); i++) {
            if ((num & con[i]) == 0) {
                a = num | con[i];
                recur(con, i, a);
            }
        }
    }
    
    int conLen(int num) {
        int result = 0;
        
        while (num != 0) {
            if (num % 2 == 1) result += 1;
            num /= 2;
        }
        
        return result;
    }
};
