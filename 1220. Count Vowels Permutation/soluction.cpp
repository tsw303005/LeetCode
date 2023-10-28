class Solution {
private:
    const int MODULE = 1e9+7;
public:
    int countVowelPermutation(int n) {
        int* pre = new int[5]{1, 1, 1, 1, 1};
        int* v = new int[5];
        int ans = 0;
        
        while (--n) {
            v[0] = (1LL * pre[1] + pre[2] + pre[4]) % MODULE;
            v[1] = (1LL * pre[0] + pre[2]) % MODULE;
            v[2] = (1LL * pre[1] + pre[3]) % MODULE;
            v[3] = pre[2];
            v[4] = (1LL * pre[2] + pre[3]) % MODULE;
            swap(pre, v);
        }
        
        for (int i = 0; i < 5; i++) {
            ans = (1LL * ans + pre[i]) % MODULE;
        }
        
        delete[] pre;
        delete[] v;
        
        return ans;
    }
};