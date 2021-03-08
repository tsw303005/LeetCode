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
    void reverse(ListNode* start, ListNode* end, int k) {
      if (start == end) {
        return ;
      }
      cout << "start = " << start->val << endl;
      cout << "end = " << end->val << endl;
      cout << "k = " << k << endl;
      ListNode* cur = start;
      ListNode* prev = NULL;
      ListNode* next = cur->next;
      
      while (k--) {
        prev = cur;
        cur = next;
        next = next->next;
        cur->next = prev;
      }
    }
  
    ListNode* reverseKGroup(ListNode* head, int k) {
      if (k == 1 || head == NULL) {
        return head;
      }
      int flag = 1;
      int run;
      int num;
      ListNode* cur = head;
      ListNode* last_end = NULL;
      ListNode* start;
      ListNode* end;

      start = cur;
      while (cur != NULL) {
        run = k;
        num = 0;
        start = cur;
        end = cur;
        while (run != 1 && cur->next != NULL) {
          //cout << "cur = " << cur->val << endl;
          cur = cur->next;
          if (cur != NULL) {
            end = cur;
          }
          num++;
          run--;
        }
        if (cur != NULL) {
          cur = cur->next;
        }
        if (flag) {
          flag = 0;
          if (run != 1) {
            return head;
          }
          reverse(start, end, num);
          head = end;
          last_end = start;
          last_end->next = NULL;
        } else {
          if (run != 1) {
            last_end->next = start;
            return head;
          }
          reverse(start, end, num);
          last_end->next = end;
          last_end = start;
          last_end->next = NULL;
        }
      }
      
      return head;
    }
};