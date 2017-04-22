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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> v;
        if(root == NULL) return v;
		
		vector<int> tmp;
		tmp.push_back(root->val);
		v.push_back(tmp);
		queue<TreeNode*> q;
		q.push(root);
		int level_sz = 1;
		
		while(!q.empty()) {
			vector<int> tmp;
			int num = 0;
			for(int i = 0; i < level_sz; ++i) {
				TreeNode * node = q.front();
				q.pop();
				
				if(node->left != NULL) {
					++num;
					tmp.push_back(node->left->val);
					q.push(node->left);
				}
				if(node->right != NULL) {
					++num;
					tmp.push_back(node->right->val);
					q.push(node->right);
				}
			}
			if(!tmp.empty()) v.push_back(tmp);
			level_sz = num;
		}
		reverse(v.begin(), v.end());
		return v;
    }
};