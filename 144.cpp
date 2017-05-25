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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
		
		TreeNode * curr = root, * prev = nullptr;
		
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
					ret.push_back(curr->val);
					prev->right = curr;
					curr = curr->left;
				} else {
					prev->right = nullptr;
					curr = curr->right;
				}
			}
		}
		return ret;
    }
};