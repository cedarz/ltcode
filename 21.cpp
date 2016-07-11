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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * ph1 = l1, * ph2 = l2;
        ListNode * head = NULL;
        ListNode * curr = NULL;
        while(ph1 && ph2) {
            if(ph1->val < ph2->val) {
                if(!head) {
                    head = ph1;
                    curr = head;
                } else {
                    curr->next = ph1;
                    curr = curr->next;
                }
                curr->next = NULL;
                ph1 = ph1->next;
            } else {
                if(!head) {
                    head = ph2;
                    curr = head;
                } else {
                    curr->next = ph2;
                    curr = curr->next;
                }
                curr->next = NULL;
                ph2 = ph2->next;
            }
        }
        if(ph1) curr->next = ph1;
        if(ph2) curr->next = ph2;
        return head;
    }
};

