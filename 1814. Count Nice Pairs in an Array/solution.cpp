const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
    const int Module = 1e9 + 7;
    
    inline int getRev(int num) {
        int result = 0;
        
        while (num != 0) {
            result *= 10;
            result += num % 10;
            num /= 10;
        }
        
        return result;
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> record;
        int rev;
        int ans = 0;
        
        for (auto &num : nums) {
            rev = getRev(num);
            record[num - rev] += 1;
        }
        
        for (auto i = record.begin(); i != record.end(); i++) {
            ans += (1LL * i->second * (i->second - 1) / 2) % Module;
            ans %= Module;
        }
        
        return ans;
    }
};
