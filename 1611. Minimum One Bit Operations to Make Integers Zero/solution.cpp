class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;

        int k = floor(log2(n));

        return pow(2, k + 1) - 1 - minimumOneBitOperations(n^(1<<k));
    }
};
