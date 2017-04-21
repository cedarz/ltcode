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
    void recoverTree(TreeNode* root) {
		
		prev = NULL;
		curr = root;
		
		TreeNode * one = NULL, * two = NULL;
		while(curr != NULL) {
			if(curr->left == NULL) {
				if(prev == NULL) {
					prev = curr;
				} else {
					if(one == NULL && prev->val > curr->val) {
						one = prev;
					}
					if(one != NULL && prev->val > curr->val) {
						two = curr;
					}
					prev = curr;
				}
				curr = curr->right;
			} else {
				TreeNode * tmp = curr->left;
				while(tmp->right != NULL && tmp->right != curr) tmp = tmp->right;
				
				if(tmp->right == NULL) {
					tmp->right = curr;
					curr = curr->left;
				} else {
					tmp->right = NULL;
					if(one == NULL && prev->val > curr->val) {
						one = prev;
					}
					if(one != NULL && prev->val > curr->val) {
						two = curr;
					}
					prev = curr;
					curr = curr->right;
				}				
			}
		}
		swap(one->val, two->val);
		
    }
	
	void inorderMorrisTraversal(TreeNode * root) {
		//
	}
	
private:
	TreeNode * prev, *curr;
};