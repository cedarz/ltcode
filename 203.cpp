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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        while(head && head->val == val) {
			ListNode * tmp = head;
			head = head->next;
			//delete tmp;
		}
		if(head == nullptr) return head;
		ListNode * p = head, * q = head->next;
		while(q != nullptr) {
			if(q->val == val) {
				ListNode * tmp = q;
				q = q->next;
				p->next = q;
				//delete tmp;
			} else {
				p = q;
				q = q->next;
			}
		}
		//p->next = NULL;
		return head;
    }
};