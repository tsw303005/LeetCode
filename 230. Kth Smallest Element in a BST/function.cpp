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
    int ans;
    int find(TreeNode* root, int now, int k) {
        if (root->left) now = find(root->left, now, k) + 1;
        if (now == k) ans = root->val;
        if (root->right) now = find(root->right, now + 1, k);
        
        return now;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        find(root, 1, k);
        
        return ans;
    }
};
