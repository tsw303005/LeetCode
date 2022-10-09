#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        
        int left, right, sum;
        long long t;
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                t = (long long)target - (long long)nums[i] - (long long)nums[j];
                left = j + 1, right = n - 1;
                
                while (left < right) {
                    sum = nums[left] + nums[right];
                    if (sum == t) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int a = nums[left], b = nums[right];
                        while (left < right and nums[left] == a) left++;
                        while (left < right and nums[right] == b) right--;
                    }
                    else if (sum > t) right--;
                    else left++;
                }
                
                while (j + 1 < n and nums[j] == nums[j+1]) j++;
            }
            
            while (i + 1 < n and nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
};
