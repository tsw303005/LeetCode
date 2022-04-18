#include <iostream>

using namespace std;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 1 && head->next == nullptr) return nullptr;
        
        ListNode* left = head;
        ListNode* right = head;
        ListNode* prev = nullptr;
        
        for (int i = 0; i < n - 1; i++, right = right->next);
        
        while (right->next != nullptr) right = right->next, prev = left, left = left->next;
        
        if (prev) prev->next = left->next;
        else head = head->next;
        
        return head;
    }
};
