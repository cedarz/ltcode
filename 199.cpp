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
    vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		if(root == nullptr) return ret;
		
        vector<TreeNode *> level;
		level.push_back(root);
		
		while(!level.empty()) {
			ret.push_back(level.back()->val);
			
			vector<TreeNode *> tmp;
			for(int i = 0; i < level.size(); ++i) {
				if(level[i]->left) tmp.push_back(level[i]->left);
				if(level[i]->right) tmp.push_back(level[i]->right);
			}
			swap(level, tmp);
		}
		return ret;
    }
};