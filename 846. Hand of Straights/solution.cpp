const static auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return nullptr;
};

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int, int> record;

        for (int i : hand) record[i] += 1;

        sort(hand.begin(), hand.end());

        for (int i = 0; i < hand.size(); ++i) {
            if (record[hand[i]] != 0) {
                for (int j = 0; j < groupSize; j++) {
                    if (record[hand[i] + j] != 0) record[hand[i] + j] -= 1;
                    else return false;
                }
            }
        }

        return true;
    }
};
