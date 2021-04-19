#include <iostream>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode* prev = nullptr;
    void recur(TreeNode* cur) {
        if (!cur) return;
        recur(cur->left);
        if (prev) {
            if (prev->val > cur->val && left == nullptr) left = prev, right = cur;
            else if (prev->val > cur->val) right = cur;
        }
        prev = cur;
        recur(cur->right);
    }
    void recoverTree(TreeNode* root) {
        recur(root);
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
    }
};