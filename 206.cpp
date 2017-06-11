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
    ListNode* reverseList(ListNode* head) {
        vector<int> all_val;
		if(head == nullptr) return head;
		
		ListNode * iter = head;
		while(iter) {
			all_val.push_back(iter->val);
			iter = iter->next;
		}
		iter = head;
		int cnt = all_val.size() - 1;
		while(iter) {
			iter->val = all_val[cnt--];
			iter = iter->next;
		}
		
		return head;
    }
};

/*
struct ListNode* reverseListRe(struct ListNode* head) {
	if(NULL==head||NULL==head->next) return head;

	struct ListNode *p=head->next;
	head->next=NULL;
	struct ListNode *newhead=reverseListRe(p);
	p->next=head;

	return newhead;
}
*/