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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
	
private:
	//vector<TreeNode*> trees;
	
	vector<TreeNode*> dfs(int low, int high) {
		vector<TreeNode *> res;
		if(low == high) {
			TreeNode * root = new TreeNode(low);
			res.push_back(root);
			return res;
		}
		for(int i = low; i <= high; ++i) {
			vector<TreeNode*> left, right;
			if(i - low > 0) {
				left = dfs(low, i - 1);
			}
			if(high - i > 0) {
				right = dfs(i + 1, high);
			}
			if(left.empty()) {
				for(int b = 0; b < right.size(); ++b) {
					TreeNode* root = new TreeNode(i);
					root->right = right[b];
					res.push_back(root);
				}
			}
			if(right.empty()) {
				for(int a = 0; a < left.size(); ++a) {
					TreeNode* root = new TreeNode(i);
					root->left = left[a];
					res.push_back(root);
				}
			}
			for(int a = 0; a < left.size(); ++a) {
				for(int b = 0; b < right.size(); ++b) {
					TreeNode* root = new TreeNode(i);
					root->left = left[a];
					root->right = right[b];
					res.push_back(root);
				}
			}
		}
		return res;
	}
};