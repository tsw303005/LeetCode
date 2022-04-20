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

class BSTIterator {
public:
    TreeNode* head;
    TreeNode* cur;
    
    BSTIterator(TreeNode* root) {
        head = new TreeNode(-1, nullptr, nullptr);
        cur = head;
        inorder(root);
    }
    
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        cur->right = root;
        cur->left = nullptr;
        cur = cur->right;
        inorder(root->right);
    }
    
    int next() {
        head = head->right;
        return head->val;
    }
    
    bool hasNext() {
        return !(head->right == nullptr);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */