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
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s;
        vector<TreeNode*> ans;
        
        for (auto &i : to_delete) s.insert(i);
        function<void(TreeNode*, bool)> dfs = [&](TreeNode* cur, bool par_remove) {
            if (!cur) return;

            bool self_remove = (s.find(cur->val) != s.end());
            dfs(cur->left, self_remove);
            dfs(cur->right, self_remove);
            if (cur->left and s.find(cur->left->val) != s.end()) cur->left = nullptr;
            if (cur->right and s.find(cur->right->val) != s.end()) cur->right = nullptr;
            if (!self_remove and par_remove) ans.push_back(cur);
            
        };
        dfs(root, true);
        
        return ans;
    }
};
