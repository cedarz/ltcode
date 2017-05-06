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
    int sumNumbers(TreeNode* root) {
		if(root == NULL) return 0;
		
		int res = root->val;
        dfs(root, res);
    }
	
	int dfs(TreeNode * root, int res) {
		if(root->left == nullptr && root->right == nullptr) {
			return res * 10 + root->val;
		} else if(root->left != nullptr && root->right == nullptr) {
			return dfs(root->left, res * 10 + root->val);
		} else if(root->left == nullptr && root->right != nullptr) {
			return dfs(root->right, res * 10 + root->val)
		} else {
			return dfs(root->left, res * 10 + root->val) + dfs(root->right, res * 10 + root->val);
		}
	}
};