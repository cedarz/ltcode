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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *, int> m;
		if(head == nullptr) return nullptr;
		
		ListNode * iter = head;
		while(iter) {
			if(m[iter]) {
				++m[iter];
				if(m[iter] == 2) {
					return iter;
				}
			} else {
				m[iter] = 1;
			}
			iter = iter->next;
		}
		return nullptr;
    }
};