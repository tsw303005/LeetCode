class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        int count[26] = {0};
        for (char c : chars) count[c - 'a'] += 1;

        for (string &word : words) {
            int tmp[26] = {0};
            for (char c : word) tmp[c - 'a'] += 1;

            for (int i = 0; i < 26; i++) {
                if (tmp[i] > count[i]) break;
                else if (i == 25) ans += word.length();
            }
        }

        return ans;
    }
};
