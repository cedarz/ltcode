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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * left = head, * right = head;
        for(int i = 0; i <= n; ++i) {
            right = right->next;
        }
        while(right != NULL) {
            left = left->next;
            right = right->next;
        }
        if(left == head) {
            head = left->next;
            delete left;
        } else {
            right = left->next;
            left->next = left->next->next;
            delete right;
        }
        return head;
        
    }
};

