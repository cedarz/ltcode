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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        ListNode * fir = head, * sec = fir->next;
        while(1) {
            if(sec) {
                int tmp = fir->val;
                fir->val = sec->val;
                sec->val = tmp;
                fir = sec->next;
                if(fir) sec = fir->next;
            } else break;
        }
        return head;
    }
};

