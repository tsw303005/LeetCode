#include <vector>

using namespace std;

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
    void recur(int height, TreeNode* cur) {
        if (ans.size() < height) ans.push_back(cur->val);
        ans[height-1] = max(cur->val, ans[height-1]);

        if (cur->left) recur(height+1, cur->left);
        if (cur->right) recur(height+1, cur->right);
    }

    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        recur(1, root);
        
        return ans;
    }
};
