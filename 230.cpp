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
    int kthSmallest(TreeNode* root, int k) {
        idx = 0;
		kth = 0;
		bst(root, k);
		return kth;
    }
	
	void bst(TreeNode * root, int k) {
		if(root == nullptr) return;
		
		bst(root->left, k);
		++idx;
		if(idx == k) {
			kth = root->val;
			return;
		}
		bst(root->right, k);
	}
private:
	int idx;
	int kth;
};