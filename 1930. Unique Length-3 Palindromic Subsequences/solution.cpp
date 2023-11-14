const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        bool record[26][26] = {false};
        
        int left, right, middle, run;
        for (int i = 0; i < 26; i++) {
            for (left = 0, right = s.length() - 1; left < right;) {
                if (s[left] != ('a' + i)) left++;
                if (s[right] != ('a' + i)) right--;
                if (s[left] == s[right] and s[left] == 'a' + i) break;
            }
            if (left < right) {
                middle = left + 1;
                run = 0;
                while (middle < right and run < 26) {
                    if (!record[i][s[middle] - 'a']) {
                        run += 1;
                        ans += 1;
                        record[i][s[middle] - 'a'] = true;
                    }
                    middle += 1;
                }
            }
        }
        
        return ans;
    }
};
