#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(arr, 0, sizeof(arr));
        ans = 0;
        
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    arr[i][j] = arr[i-1][j-1] + 1;
                }
                ans = max(arr[i][j], ans);
            }
        }
        
        return ans;
    }
private:
    int arr[1001][1001];
    int ans;
};
