/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> m;
		RandomListNode * iter = head;
		m[NULL] = NULL;
		while(iter != NULL) {
			if(!m[iter]) {
				RandomListNode * tmp = new RandomListNode(iter->label);
				m[iter] = tmp;
			}
			iter = iter->next;
		}
		iter = head;
		RandomListNode * res = NULL, * p = NULL;
		res = m[iter];
		p = res;
		while(iter != NULL) {
			p->next = m[iter->next];
			p->random = m[iter->random];
			iter = iter->next;
			p = p->next;
		}
		return res;
    }
};