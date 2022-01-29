#include <iostream>
#include <vector>
#include <priority_queue>
#include <queue>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> p;
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        for (auto v : lists) {
            if (v != nullptr) p.push(v);
        }
        while (!p.empty()) {
            if (cur) cur->next = p.top(), cur = cur->next;
            else cur = head = p.top();
            if (p.top()->next) {
                p.push(p.top()->next);
            }
            cur->next = nullptr;
            p.pop();
        }
        return head;
    }
};