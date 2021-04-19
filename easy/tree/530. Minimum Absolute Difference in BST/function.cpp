
#include <iostream>
#include <limits.h>
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
    int left = INT_MAX;
    int ans = INT_MAX;
    void recur(TreeNode* cur) {
        if (cur->left) recur(cur->left);
        if (left != INT_MAX) ans = min(ans, abs(cur->val-left));
        left = cur->val;
        if (cur->right) recur(cur->right);
    }
    int getMinimumDifference(TreeNode* root) {
        recur(root);
        return ans;
    }
};