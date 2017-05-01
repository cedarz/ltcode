/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // full路径只有部分，不会跨root；可以是half值，root->val值
 // half则必须要连接root结点啦
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
		
		int half = 0, full = 0;
		dfs(root, half, full);
		
		return std::max(half, full);
    }
	
	void dfs(TreeNode * root, int & half, int & full) {
		if(root->left == NULL && root->right == NULL) {
			half = root->val;
			full = root->val;
		} else if(root->left == NULL && root->right != NULL) {
			//full = 0;
			int h = 0, f = 0;
			dfs(root->right, h, f);
			half = root->val;
			half = std::max(half, root->val + h);
			full = half;
			full = std::max(full, std::max(root->val, f));
		} else if(root->left != NULL && root->right == NULL) {
			int h = 0, f = 0;
			dfs(root->left, h, f);
			half = root->val;
			half = std::max(half, root->val + h);
			full = half;
			full = std::max(full, std::max(root->val, f));
		} else {
			int lh = 0, lf = 0;
			int rh = 0, rf = 0;
			dfs(root->left, lh, lf);
			dfs(root->right, rh, rf);
			half = root->val;
			half = std::max(half, root->val + std::max(lh, rh));
			full = std::max(half, std::max(lh, rh));
			full = std::max(full, std::max(lf, rf));
			full = std::max(full, root->val + lh + rh);
		}
		cout << half << " " << full << endl;
	}
};