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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode * one = head, * two = head;
		while(true) {
			if(one->next) {
				one = one->next;
			} else {
				return false;
			}
			if(two->next && two->next->next) {
				two = two->next->next;
			} else {
				return false;
			}
			if(one == two) {
				return true;
			}
		}
    }
};