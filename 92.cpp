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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode * H = new ListNode(0);
        H->next = head;
		ListNode * m_1 = H, * mth = head;
		int loc  = 1;
		while(loc < m) {
			m_1 = mth;
			mth = mth->next;
			++loc;
		}
		
		//ListNode * now = m;
		//++loc;
		while(loc < n) {
			++loc;
			ListNode * p = mth->next;
			mth->next = p->next;
			p->next = m_1->next;
			m_1->next = p;
		}
		return H->next;
    }
};