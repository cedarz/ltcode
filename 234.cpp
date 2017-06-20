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
    bool isPalindrome(ListNode* head) {
        int cnt = 0;
		ListNode * tmp = head;
		while(tmp) {
			++cnt;
			tmp = tmp->next;
		}
    }
};