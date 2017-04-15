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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
		
		ListNode * loc = NULL, * res = NULL, * H = NULL;
		ListNode * pre = head, *now = pre->next;
		
		if(head->val < x) {
			loc = head;
		} else {
			H = head;
		}
		while(now != NULL) {
			if(now->val < x) {
				pre->next = now->next;
				if(loc == NULL) {
					now->next = res;
					loc = now;
					res = now;
				} else {
					now->next = loc->next;
					loc->next = now;
					loc = now;
				}
			} else {
				if(H == NULL) H = now;
				pre = now;
			}
			now = pre->next;
		}
		loc->next = H;
		return res;
		
    }
};