#include <vector>
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        ans.clear();
        if (root) recur(root, 0);
        
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    void recur(Node *cur, int level) {
        if (ans.size() <= level) ans.push_back({});
        ans[level].emplace_back(cur->val);

        for (auto &node : cur->children) {
            recur(node, level + 1);
        }
    }
};
