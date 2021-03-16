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
#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* record_prev;
        ListNode* next = NULL;
        ListNode* tail = NULL;
        
        for (int i = 0; i < left-1; i++) {
            record_prev = cur;
            cur = cur->next;
        }
        
        next = cur->next;
        for (int i = 0; i < right-left; i++) {
            if (i == 0) {
                tail = cur;
            }
            prev = cur;
            cur = next;
            next = next->next;
            cur->next = prev;
        }
        
        if (record_prev != NULL) {
            record_prev->next = cur;
        } else {
            head = cur;
        }
        
        tail->next = next;
        return head;
    }
};