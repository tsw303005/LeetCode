#include <iostream>
#include <utility>
#include <algorithm>

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
typedef pair<int, int> result;

class Solution {
public:
    result recur(TreeNode* root) {
        int maxPath = root->val;
        int maxSubPath = root->val;
        
        if (root->left) {
            auto child = recur(root->left);
            maxPath = max(maxPath, child.first);
            maxPath = max(maxPath, child.second + root->val);
            maxSubPath = max(maxSubPath, child.second + root->val);
        }
        if (root->right) {
            auto child = recur(root->right);
            maxPath = max(maxPath, child.first);
            maxPath = max(maxPath, maxSubPath + child.second);
            maxSubPath = max(maxSubPath, root->val + child.second);
        }
        
        return {maxPath, maxSubPath};
    }
    
    int maxPathSum(TreeNode* root) {
        return recur(root).first;
    }
};
