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
	ListNode * merge(ListNode * left, ListNode * mid, ListNode * right) {
		mid->next = right;
		if(left == nullptr) {
			return mid;
		} else {
			ListNode * iter = left;
			while(iter->next) {
				iter = iter->next;
			}
			iter->next = mid;
			return left;
		}
	}
    ListNode* sortList(ListNode* head) {
        ListNode * left = nullptr, * right = nullptr;
		ListNode * lp = nullptr, * rp = nullptr;
		
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
			if(lp) lp->next = nullptr;
			if(rp) rp->next = nullptr;
			ListNode * res_l = sortList(left);
			ListNode * res_r = sortList(right);
			return merge(res_l, pivot, res_r);
		}
    }
};