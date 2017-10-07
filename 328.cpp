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
    ListNode* oddEvenList(ListNode* head) {
        ListNode * odd = NULL, * even = NULL;
		ListNode * odd_t = NULL, * even_t = NULL;
		
		if(head == nullptr) return head;
		int cnt = 0;
		while(head) {
			++cnt;
			if(cnt & 1) {
				odd ? odd_t->next = head, odd_t = head :
						odd = head, odd_t = head;
			} else {
				even ? even_t->next = head, even_t = head:
						even = head, even_t = head;
			}
			head = head->next;
		}
		if(odd_t) odd_t->next = even;
		else odd = even;
		if(even_t) even_t->next = nullptr;
		return odd;
    }	
};