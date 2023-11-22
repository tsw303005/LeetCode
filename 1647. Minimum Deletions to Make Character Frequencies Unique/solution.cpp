class Solution {
public:
    int minDeletions(string s) {
        int record[27] = {0};
        int ans = 0;
        unordered_set<int> us;
        for (auto c : s) record[c - 'a'] += 1;
        
        for (int i = 0; i < 26; i++) {
            while (record[i] > 0 and us.find(record[i]) != us.end()) record[i]--, ans++;
            us.insert(record[i]);
        }
        
        return ans;
    }
};
