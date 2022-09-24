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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        recur(root, targetSum, 0);
        
        return ans;
    }
private:
    vector<int> v;
    vector<vector<int>> ans;
    
    void recur(TreeNode *cur, int targetSum, int now) {
        if (!cur) return;

        v.emplace_back(cur->val);
        if (now + cur->val == targetSum and !cur->left and !cur->right) {
            ans.emplace_back(v);
        } else {
            recur(cur->left, targetSum, now + cur->val);
            recur(cur->right, targetSum, now + cur->val);
        }
        v.pop_back();
    }
};
