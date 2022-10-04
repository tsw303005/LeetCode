
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (not root) return false;
        else if (not root->left and not root->right and targetSum == root->val) return true;
        
        targetSum -= root->val;
        return hasPathSum(root->left, targetSum) or hasPathSum(root->right, targetSum);
    }
};
