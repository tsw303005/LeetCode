class Solution {
private:
    const vector<char> vowel_list = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
public:
    string sortVowels(string s) {
        vector<int> record(10, 0);
        
        
        for (auto &letter : s) {
            for (int i = 0; i < 10; i++) {
                if (letter == vowel_list[i]) {
                    record[i]++;
                    break;
                }
            }
        }
        
        int run = 0;
        for (int i = 0; i < s.length(); i++) {
            while (run < 10 and !record[run]) run++;
            if (run >= 10) break; 
            
            for (int j = 0; j < 10; j++) {
                if (s[i] == vowel_list[j]) {
                    s[i] = vowel_list[run];
                    record[run]--;
                    break;
                }
            }
        }
        
        return s;
    }
};
