/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> ans;
public:
    vector<int> findMode(TreeNode* root) {
        int Max = -1;
        int prev = INT_MIN;
        int run = 0;
        
        function<void(TreeNode*)> dfs = [&](TreeNode* cur) {
            if (cur->left) dfs(cur->left);
            if (cur->val != prev) {
                if (run >= Max) {
                    if (run > Max) {
                        Max = run;
                        ans.clear();
                    }
                    ans.push_back(prev);
                }
                run = 0;
                prev = cur->val;
            }
            run += 1;

            if (cur->right) dfs(cur->right);
        };
        
        dfs(root);
        if (run >= Max) {
            if (run > Max) {
                ans.clear();
            }
            ans.push_back(prev);
        }
        
        return ans;
    }
};
