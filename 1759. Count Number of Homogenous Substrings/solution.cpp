class Solution {
private:
    const int Module = 1e9 + 7;
public:
    int countHomogenous(string s) {
        int ans = 0;
        int pre = 0;
        int height;
        int size = s.length();
        
        for (int i = 0; i < size; i++) {
            if (s[i] != s[pre]) {
                height = i - pre;
                ans += (1LL * (1 + height) * height / 2) % Module;
                pre = i;
            }
        }
        height = size - pre;
        ans += (1LL * (1 + height) * height / 2) % Module;
        
        return ans;
    }
};
