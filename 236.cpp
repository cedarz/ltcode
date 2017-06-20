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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p_path;
		vector<TreeNode *> q_path;
		
		dfs(root, p_path, p);
		dfs(root, q_path, q);
		
		cout << p_path.size() << " " << q_path.size() << endl;
		int i = 0, j = 0;
		while(i < p_path.size() && j < q_path.size() && p_path[i]->val == q_path[j]->val) {
		    ++i, ++j;
		}
		
		return p_path[i - 1];
		
    }
	
	bool dfs(TreeNode * root, vector<TreeNode *> & path, TreeNode * target) {
		if(root == nullptr) return false;
		
		if(root == target) {
			path.push_back(root);
			return true;
		} else {
			path.push_back(root);
			bool left = dfs(root->left, path, target);
			if(left) return true;
			else {
				path.pop_back();
			}
			
			path.push_back(root);
			bool right = dfs(root->right, path, target);
			if(right) return true;
			else {
				path.pop_back();
			}
			
			return false;
		}
	}
};