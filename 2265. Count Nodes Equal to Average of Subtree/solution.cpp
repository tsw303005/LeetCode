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
    int ans;
public:
    int averageOfSubtree(TreeNode* root) {
        using P = pair<int, int>;
        ans = 0;
        
        function<P(TreeNode*)> dfs = [&](TreeNode* cur) -> P {
            if (!cur) return {0, 0};
            auto left = dfs(cur->left);
            auto right = dfs(cur->right);
            int num_node = left.first + right.first + 1;
            int total = left.second + right.second + cur->val;
            if (total / num_node == cur->val) ans += 1;
            
            return {num_node, total};
        };
        
        dfs(root);
        
        return ans;
    }
};
