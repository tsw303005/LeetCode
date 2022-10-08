#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int ans, sum, j, k;
        ans = nums[0]+nums[1]+nums[2];
        
        for (int i = 0; i < nums.size()-2 and ans != target; i++) {
            j = i+1, k = nums.size()-1;
            
            while (j < k and ans != target) {
                sum = nums[i] + nums[j] + nums[k];
                if (abs(sum-target) < abs(ans-target)) ans = sum;
                
                if (sum > target) k--;
                else j++;
            }
        }
        
        return ans;
    }
};
