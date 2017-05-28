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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return nullptr;
		
		ListNode * iter = head->next;
		head->next = nullptr;
		
		while(iter) {
			ListNode * p = head;
			if(iter->val < head->val) {
			    cout << "here" << endl;
				ListNode * tmp = iter;
				iter = iter->next;
				tmp->next = head;
				head = tmp;
			} else {
				while(p->next && p->next->val < iter->val) {
					p = p->next;
				}
				//cout << p->val << endl;
				ListNode * tmp = iter;
				iter = iter->next;
				tmp->next = p->next;
				p->next = tmp;
			}
		}
		return head;
    }
};