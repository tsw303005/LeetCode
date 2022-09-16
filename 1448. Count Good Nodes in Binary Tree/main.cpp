#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        ans = 0;
        recur(root, root->val);
        
        return ans;
    }
private:
    int ans;
    void recur(TreeNode* cur, const int &Max) {
        if (cur->val >= Max) ans += 1;
        if (cur->left) recur(cur->left, max(Max, cur->val));
        if (cur->right) recur(cur->right, max(Max, cur->val));
    }
};
