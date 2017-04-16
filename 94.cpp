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
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
		return tree;
    }

private:
	vector<int> tree;
	
	void dfs(TreeNode * root) {
	    if(root == nullptr) return;
		if(root->left != nullptr) inorderTraversal(root->left);
		tree.push_back(root->val);
		if(root->right != nullptr) inorderTraversal(root->right);
	}
};