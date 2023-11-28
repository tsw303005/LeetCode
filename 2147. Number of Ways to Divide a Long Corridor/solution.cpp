const static auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return nullptr;
};

class Solution {
const int Mod = 1e9 + 7;
public:
    int numberOfWays(string corridor) {
        int count = 0;
        for (auto &i : corridor) {
            if (i == 'S') count += 1;
        }
        // not valid
        if (count & 1) return 0;
        else if (count == 0) return 0;
        else if (count == 2) return 1;

        int ans = 1;
        int result = 1;
        count = 0;
        for (char &i : corridor) {
            if (i == 'P' and count == 2) result += 1;
            else if (i == 'S' and count == 2) count = 1, ans = (1LL * ans * result) % Mod, result = 1;
            else if (i == 'S') count += 1;
        }

        return ans;
    }
};