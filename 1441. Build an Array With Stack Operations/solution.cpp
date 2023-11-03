class Solution {
private:
    vector<string> ans;
public:
    vector<string> buildArray(vector<int>& target, int n) {
        ans.clear();
        
        for (int i = 0; i < target.size(); i++) {
            for (int j = (i == 0) ? 1 : target[i-1] + 1; j < target[i]; j++) {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
        }
        
        return ans;
    }
};
