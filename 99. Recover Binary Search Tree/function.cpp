#include <iostream>
using namespace std;

/*
用單調遞增去想
當在跑 inorder 的時候紀錄上一個數字是多少
如果下一個要列印的數字比上一個還要小，就去更新 left, right
只有第一次遇到的時候要更新 left
後面都是更新 right
*/

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