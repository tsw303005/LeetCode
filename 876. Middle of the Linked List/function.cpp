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
using namespace std;

typedef struct _ListNode {
  struct _ListNode* next;
  int val;
}ListNode;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* cur = head;
        int count = 0;
        
        while (cur != NULL) {
            cur = cur->next;
            count += 1;
        }
        cur = head;
        for (int i = 0; i < count / 2; i++) {
            cur = cur->next;
        }
        
        return cur;
    }
};