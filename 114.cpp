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
    void flatten(TreeNode* root) {
		if(root == NULL) return;
        
		else {
			TreeNode * left = root->left, * right = root->right;
			root->left = NULL;
			root->right = left;
			flatten(left);
			TreeNode * r = root;
			while(r->right != NULL) r = r->right;
			r->right = right;
			flatten(right);
		}
    }

};