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
	ListNode * merge(ListNode * left, ListNode * mid, ListNode * right, ListNode * m_tail) {
		m_tail->next = right;
		return left == nullptr ? mid : left;
	}
    ListNode* sortList(ListNode* head) {
        ListNode * left = nullptr, * right = nullptr;
		ListNode * lp = nullptr, * rp = nullptr, * mp = head;
		
		ListNode * pivot = head;
		
		if(pivot == nullptr) return nullptr;
		else if(head->next == nullptr) {
			return head;
		} else {
			ListNode * iter = head->next;
			while(iter) {
				if(iter->val < pivot->val) {
					if(left == nullptr) {
						left = iter;
						lp = left;
					} else {
						lp->next = iter;
						lp = iter;
					}
				} else if(iter->val == pivot->val) { // same
					mp->next = iter;
					mp = iter;
				} else {
					if(right == nullptr) {
						right = iter;
						rp = right;
					} else {
						rp->next = iter;
						rp = iter;
					}
				}
				iter = iter->next;
			}
			mp->next = nullptr;
			if(lp) {
				//lp->next = nullptr;
				lp->next = pivot; // pivot as left tail, mp as mid tail
			}
			if(rp) rp->next = nullptr;
			ListNode * res_l = sortList(left);
			ListNode * res_r = sortList(right);
			return merge(res_l, pivot, res_r, mp); // pivot 
		}
    }
};