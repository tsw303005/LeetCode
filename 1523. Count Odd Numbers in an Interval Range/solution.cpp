class Solution {
public:
    int countOdds(int low, int high) {
        if ((high - low + 1) & 1 and low & 1) return (high - low + 1) / 2 + 1;
        else return (high - low + 1) / 2;
    }
};
