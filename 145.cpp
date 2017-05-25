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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode * curr = nullptr, * prev = nullptr;
		
		TreeNode * sr = new TreeNode(-1);
		sr->left = root;
		curr = sr;
		
		vector<int> ret; 
		
		while(curr) {
			if(curr->left == nullptr) {
				ret.push_back(curr->val);
				curr = curr->right;
			} else {
				prev = curr->left;
				while(prev->right != nullptr && prev->right != curr) {
					prev = prev->right;
				}
				
				if(prev->right == nullptr) {
					prev->right = curr;
					curr = curr->left;
				} else {
				    ret.push_back(curr->left->val);
					prev->right = nullptr;
					curr = curr->right;
				}
			}
		}
		return ret;
    }
};