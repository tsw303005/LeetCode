#include <iostream>

using namespace std;


//  * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur = nullptr;
        ListNode *ans = nullptr;
        
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        
        if (list1->val <= list2->val) ans = list1, list1 = list1->next;
        else ans = list2, list2 = list2->next;
        
        cur = ans;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) cur->next = list1, list1 = list1->next;
            else cur->next = list2, list2 = list2->next;
            cur = cur->next;
        }
        
        if (list1 == nullptr) cur->next = list2;
        else cur->next = list1;
        
        return ans;
    }
};