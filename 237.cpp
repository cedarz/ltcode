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
    void deleteNode(ListNode* node) {
		if(node->next == nullptr) {
			ListNode * tmp = node;
			node = nullptr;
			delete tmp;
			return;
		}
		
		ListNode * next = node->next;
		while(true) {
			node->val = next->val;
			if(next->next == nullptr) {
				node->next = nullptr;
				delete next;
				return;
			}
			node = next;
			next = next->next;
		}
    }
};