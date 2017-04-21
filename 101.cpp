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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
		else {
			return is_sym(root->left, root->right);
		}
    }
	bool is_sym(TreeNode * left, TreeNode * right) {
		if(left == NULL && right == NULL) return true;
		else if(left == NULL || right == NULL) return false;
		else return left->val == right->val && is_sym(left->left, right->right) &&
						is_sym(left->right, right->left);
	}
};