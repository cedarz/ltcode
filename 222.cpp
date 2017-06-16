/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int countNodes(TreeNode* root) {
		if(root == nullptr) return 0;
		
		int hl = 0, hr = 0;
		TreeNode * ltmp = root;
		while(tmp) {
			++hl;
			tmp = tmp->left;
		}
		tmp = root;
		while(tmp) {
			++hr;
			tmp = tmp->right;
		}
		if(hl == hr) return pow(2, hl) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right);		
    }
	
    int countNodes_tle(TreeNode* root) {
		if(root == nullptr) return 0;
        int cnt = 0; 
		queue<TreeNode *> q;
		q.push(root);
		while(!q.empty()) {
			TreeNode * tmp = q.front();
			++cnt;
			q.pop();
			if(tmp->left) {
				q.push(tmp->left);
			}
			if(tmp->right) {
				q.push(tmp->right);
			}
		}
		return cnt;
    }
};