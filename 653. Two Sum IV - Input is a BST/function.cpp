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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        recur(root, v);
        
        int left, right;
        left = 0, right = v.size() - 1;
        
        while (left < right) {
            if (v[left] + v[right] == k) return true;
            else if (v[left] + v[right] > k) right--;
            else left++;
            
        }
        
        return false;
    }
    
    void recur(TreeNode* cur, vector<int> &v) {
        if (cur->left) recur(cur->left, v);
        v.push_back(cur->val);
        if (cur->right) recur(cur->right, v);
    }
};
