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
    int recur(TreeNode* root, int val) {
        if (!root) return 0;
        
        int plus = recur(root->right, val);
        int tmp = plus;
        
        plus += root->val;
        root->val += (tmp + val);

        plus += recur(root->left, plus + val);
        
        return plus;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        recur(root, 0);
        
        return root;
    }
};
