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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode * first = head, * kth = head;
        for(int i = 0; i < k; ++i) {
            kth = kth->next;
            if(!kth) {
                k %= (i + 1);
                i = -1;
                kth = head;
            }
        }
        if(!kth) return head;
        while(kth->next) {
            first = first->next;
            kth = kth->next;
        }
        kth->next = head;
        head = first->next;
        first->next = NULL;
        return head;
    }
};


