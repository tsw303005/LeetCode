class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            ans = (nums[i][i] == '1') ?  ans + "0" : ans + "1";
        }
        
        return ans;
    }
};
