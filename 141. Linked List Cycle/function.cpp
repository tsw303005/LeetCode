/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        if (cur == NULL) return false;
        while (cur->next != NULL && cur->next != head) {
            prev = cur;
            cur = cur->next;
            prev->next = head;
        }
        if (cur->next == NULL) return false;
        else return true;
    }
};