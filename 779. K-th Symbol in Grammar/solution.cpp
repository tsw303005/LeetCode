class Solution {
public:
    int recur(int n, int k) {
        if (n == 1 || k == 1) return 0;
        
        if (k % 2 == 0) {
            if (recur(n-1, k/2) == 1) return 0;
            else return 1;
        } else {
            if (recur(n-1, (k+1)/2) == 1) return 1;
            else return 0;
        }
    }
    int kthGrammar(int n, int k) {
        return recur(n, k);
    }
};
