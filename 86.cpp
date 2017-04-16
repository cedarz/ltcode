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

		
		
		while(true) {
			bool flag = false;
			
			ListNode * pre = head, *now = pre->next;
			while(now != NULL) {
				if(pre->val >= x && now->val < x) {
					swap(pre->val, now->val);
					flag = true;
				}
				pre = now;
				now = pre->next;
			}
			if(!flag) break;
		}
		
		return head;
    }
};

