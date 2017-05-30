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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * A = headA, * B = headB;
		// len A + len B + 1 (null) = len B + len A + 1 (null)
		while(A != B) {
			A = A ? A->next : headB;
			B = B ? B->next : headA;
		}
		
		return A;
    }
};