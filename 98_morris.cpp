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
    bool isValidBST(TreeNode* root) {
		if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) {
			return true;
		}else if(root->left != NULL && root->right == NULL) {
			return root->val > max_dfs(root->left) && isValidBST(root->left);
		} else if(root->left == NULL && root->right != NULL){
			return root->val < min_dfs(root->right) && isValidBST(root->right);
		} else {
			return root->val > max_dfs(root->left) && min_dfs(root->right) 
					&& isValidBST(root->right) && isValidBST(root->left);
		}
    }
	int min_dfs(TreeNode * root) {
		while(root->left != NULL) {
			root = root->left;
		}
		return root->val;
	}
	int max_dfs(TreeNode * root) {
		while(root->right != NULL) {
			root = root->right;
		}
		return root->val;
	}
};