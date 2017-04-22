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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
		
		int h = 0;
		return dfs(root, h);
    }

	bool dfs(TreeNode * root, int & h) {
		if(root == NULL) {
			h = 0;
			return true;
		} else {
			int l = 0, r = 0;
			bool bl = dfs(root->left, l);
			bool br = dfs(root->right, r);
			h = 1 + max(l, r);
			return l - r <= 1 && l - r >= -1;			
		}
	}
};