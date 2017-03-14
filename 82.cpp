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
        ListNode * h = NULL, * p = head, * q = p;
        ListNode * iter = head; 
        head = NULL;
        while(iter != nullptr) {
            while(iter->next != nullptr && iter->next->val == p->val) {
                q = q->next;
                iter = iter->next;
            }
            //cout << p->val << " " << q->val << " " << iter->val << endl;
            iter = iter->next;
            if(p == q) {
                if(h == nullptr) {
                    head = h = p;
                } else {
                    h->next = p;
                    h = h->next;
                }
                h->next = NULL;
            } else {
                while(p != q) {
                    ListNode * r = p;
                    p = p->next;
                    free(r);
                }
                free(q);
            }
            
            q = p = iter;
        }
        return head;
    }
};


