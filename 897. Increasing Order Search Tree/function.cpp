#include <iostream>

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
public:
    TreeNode* run = nullptr;
    TreeNode* ans = nullptr;
    
    void recur(TreeNode* cur) {
        if (!cur) return;
        if (cur->left) recur(cur->left);
        
        TreeNode* right = cur->right;
        if (!ans) ans = cur, run = ans;
        else run->right = cur, run = run->right;
        run->left = nullptr;
        
        recur(right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        recur(root);
        
        return ans;
    }
};
