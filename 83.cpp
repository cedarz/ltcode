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
    ListNode* deleteDuplicates(ListNode* head) {
        if(nullptr == head) return head;
        ListNode * h = head, * iter = head->next;
        
        while(iter != nullptr) {
            if(iter->val == h->val) {
                ListNode r = iter;
                iter = iter->next;
                free(r);
            } else {
                h->next = iter;
                iter = iter->next;
                h = h->next;
            }
        }
        h->next = nullptr;
        return head;
    }
};

