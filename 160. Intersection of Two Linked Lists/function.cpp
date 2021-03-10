/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

typedef struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        int countB = 0;
        
        ListNode* cur = headA;
        ListNode* com;
        while (cur != NULL) {
            countA += 1;
            cur = cur->next;
        }
        cur = headB;
        while (cur != NULL) {
            countB += 1;
            cur = cur->next;
        }
        int run = 0;
        if (countA > countB) {
            run = countA - countB;
            cur = headA;
            com = headB;
            for (int i = 0; i < run; i++) {
                cur = cur->next;
            }
        } else if (countB > countA) {
            run = countB - countA;
            cur = headB;
            com = headA;
            for (int i = 0; i < run; i++) {
                cur = cur->next;
            }
        } else {
            cur = headA;
            com = headB;
        }
        
        while (cur != com) {
            cur = cur->next;
            com = com->next;
        }
        
        if (cur == NULL) {
            return NULL;
        } else {
            return cur;
        }
    }
};