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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            auto cur = new TreeNode(val);
            
            cur->left = root;
            return cur;
        }
        
        recur(root, val, depth, 1);
        
        return root;
    }
    
    void recur(TreeNode* cur, int val, int depth, int now) {
        if (now+1 == depth) {
            auto left = cur->left;
            auto right = cur->right;
            cur->left = new TreeNode(val);
            cur->right = new TreeNode(val);
            
            cur->left->left = left;
            cur->right->right = right;
            return;
        }
        if (cur->left) {
            recur(cur->left, val, depth, now+1);
        }
        if (cur->right) {
            recur(cur->right, val, depth, now+1);
        }
    }
};
