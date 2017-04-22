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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
		else {
			int l = minDepth(root->left);
			int r = minDepth(root->right);
			//cout << root->val << " " << l << " " << r << " " << (l & r) << endl;
			if(l && r) { // wrong if &
				return 1 + min(l, r);
			} else {
				return 1 + max(l, r);
			}
		}
    }
};