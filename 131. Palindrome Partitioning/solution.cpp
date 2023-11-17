const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
    // check if palindrome and record
    vector<vector<int>> isPalindromeRecord;
    bool isPalindrome(int left, int right, string &s) {
        if (isPalindromeRecord[left][right] != 2) return isPalindromeRecord[left][right];
        while (left < right and s[left] == s[right]) {
            left++;
            right--;
        }
        
        isPalindromeRecord[left][right] = (left >= right) ? 1 : 0;
        return isPalindromeRecord[left][right];
    }
    
    // ans is for record valid result
    vector<vector<string>> ans;
    void findPalindrome(int left, int right, string &s, vector<string> &record) {
        // left bigger right means that we find a valid answer
        // push the whole record array to ans then return
        if (left > right) {
            ans.push_back(record);
            return;
        }
        
        // every time the record arrays record valid array before 0 ~ left
        // in the above for loop, it will find all valid answer in left ~ right
        for (int i = left; i <= right; i++) {
            if (isPalindrome(left, i, s)) {
                record.push_back(s.substr(left, i - left + 1));
                findPalindrome(i + 1, right, s, record);
                record.pop_back();
            }
        }
    }
    

public:
    vector<vector<string>> partition(string s) {
        // init
        vector<string> record;
        isPalindromeRecord = vector<vector<int>>(16, vector<int>(16, 2));
        
        // find valid answer
        findPalindrome(0, s.length() - 1, s, record);

        return ans;
    }
};
