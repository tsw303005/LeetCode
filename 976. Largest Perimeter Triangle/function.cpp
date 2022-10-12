#include <vector>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return a > b;
        });

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i-1] + nums[i] > nums[i-2]) return nums[i-1] + nums[i-2] + nums[i];
        }
        
        return 0;
    }
};
