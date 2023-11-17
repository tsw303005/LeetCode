class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // find min and max value in nums
        int Min = 1e5, Max = 0;
        
        // store number in array
        int *arr = new int[100001];
        memset(arr, 0, sizeof(int) * 100001);
        for (auto &i : nums) {
            Min = min(i, Min);
            Max = max(i, Max);
            arr[i]++;
        }
        
        // find ans
        int ans = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            while (!arr[Min]) Min++;
            while (!arr[Max]) Max--;
            ans = max(Max + Min, ans);
            arr[Min]--;
            arr[Max]--;
        }
        
        return ans;
    }
};
