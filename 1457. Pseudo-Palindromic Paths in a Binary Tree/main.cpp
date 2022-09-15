#include <iostream>
#include <vector>

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
    int pseudoPalindromicPaths (TreeNode* root) {
        arr = new int[10];
        ans = left = 0;
        for (int i = 0; i < 10; i++) arr[i] = 0;
        recur(root);
        return ans;
    }
private:
    int ans;
    int *arr;
    int left;
    void recur(TreeNode* cur);
};

void Solution::recur(TreeNode* cur) {
    int num = (arr[cur->val] == 1) ? -1 : 1;
    if (num == 1) left++;
    else left--;

    arr[cur->val] += num;
    if (cur->left) recur(cur->left);
    if (cur->right) recur(cur->right);
    if (!cur->left && !cur->right && left <= 1) ans++;
    arr[cur->val] -= num;
    if (num == 1) left--;
    else left++;
}
