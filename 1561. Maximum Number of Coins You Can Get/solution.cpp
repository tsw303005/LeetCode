#pragma GCC optimize("O3")

const static auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return nullptr;
}();

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        int left = 0, right = piles.size() - 1;
        sort(piles.begin(), piles.end());
        while (left < right) {
            ans += piles[right-1];
            right -= 2;
            left += 1;
        }
        
        return ans;
    }
};
