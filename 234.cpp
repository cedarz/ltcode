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
		if(cnt <= 1) return true;
		
		int right = (cnt + 1) / 2 + 1; // left start
		int left = cnt / 2;
		
		tmp = head;
		cnt = 0;
		ListNode * L = nullptr;
		while(tmp) {
			++cnt;
			if(cnt == left) {
				L = tmp;
			}
			if(cnt == right) {
				R = tmp;
				break;
			}
			tmp = tmp->next; // forget
		}
		//cout << left << " " << right << endl;
		//cout << L->val << " " << R->val << endl;
		return dfs(head, L);
    }
	
	bool dfs(ListNode * head, ListNode * L) {
		if(head == L->next) return true;
		else {
			bool flag = dfs(head->next, L);
			//cout << head->val << " " << R->val << endl;
			if(!flag) return false;
			bool ret = flag && head->val == R->val;
			R = R->next;
			return ret;
		}
	}
private:
	ListNode * R;
};