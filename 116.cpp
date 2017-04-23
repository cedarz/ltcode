/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
		
		queue<TreeLinkNode*> q;
		q.push(root);
		int level_sz = 1;
		root->next = NULL;
		
		while(!q.empty()) {
			TreeLinkNode* prev = NULL;
			int next_sz = 0;
			for(int i = 0; i < level_sz; ++i) {
				TreeLinkNode * curr = q.front();
				q.pop();
				
				if(curr->left != NULL) {
					++next_sz;
					if(prev == NULL) {
						prev = curr->left;
					} else {
						prev->next = curr->left;
						prev = curr->left;
						
					}
					q.push(curr->left);
					prev->next = NULL;
				}
				if(curr->right != NULL) {
					++next_sz;
					if(prev == NULL) {
						prev = curr->right;
					} else {
						prev->next = curr->right;
						prev = curr->right;
						
					}
					q.push(curr->right);
					prev->next = NULL;
				}
			}
			level_sz = next_sz;
		}
    }
};