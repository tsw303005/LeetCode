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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = NULL;
        ListNode* big = NULL;
        ListNode* cur = head;
        ListNode* tail = NULL;
        ListNode* big_head = NULL;
        
        while (cur != NULL) {
            if (cur->val < x) {
                if (small == NULL) {
                    small = cur;
                    head = cur;
                    tail = cur;
                } else {
                    small->next = cur;
                    small = small->next;
                    tail = small;
                }
            } else {
                if (big == NULL) {
                    big = cur;
                    big_head = cur;
                } else {
                    big->next = cur;
                    big = big->next;
                }
            }
            cur = cur->next;
        }
        if (big != NULL) {
            big->next = NULL;
        }
        if (tail != NULL) {
            tail->next = big_head;
        }
        return head;
    }
};