
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;
        ListNode* cur = head;
        ListNode* middle = head;
        ListNode* prev = head;
        bool flag = true;
        
        while (cur) {
            flag = !flag;
            if (flag) {
                prev = middle;
                middle = middle->next;
            }
            cur = cur->next;
        }
        
        prev->next = middle->next;
        delete middle;
        
        return head;
    }
};
