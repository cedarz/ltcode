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
    void reorderList(ListNode* head) {
		
		ListNode * iter = head;
		vector<ListNode *> nodes;
		
		while(iter) {
			nodes.push_back(iter);
			iter = iter->next;
		}
		//if(nodes.size() <= 2) return head;
		
		int len = nodes.size();
		
		for(int i = 0; i < (len + 1) / 2; ++i) {
			if(i == 0) {
				head = nodes[i];
				iter = head;
			} else {
				iter->next = nodes[i];
				iter = iter->next;
			}
			if(nodes[len - 1 - i] && i != len - 1 - i) {
				iter->next = nodes[len - 1 - i];
				iter = iter->next;
			}
		}
		iter->next = nullptr;
    }
};