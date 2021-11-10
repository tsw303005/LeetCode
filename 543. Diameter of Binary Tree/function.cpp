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

class Solution
{
public:
  int ans = INT_MIN;
  int recur(TreeNode *cur)
  {
    if (cur)
    {
      int left = recur(cur->left);
      int right = recur(cur->right);
      ans = max(ans, left + right);
      return max(left, right) + 1;
    }
    else
      return 0;
  }
  int diameterOfBinaryTree(TreeNode *root)
  {
    int left = recur(root->left);
    int right = recur(root->right);
    ans = max(left + right, ans);
    return ans;
  }
};