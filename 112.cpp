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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if(root == NULL) {
			res.clear();
			return res;
		}
		vector<int> tmp;
        dfs(root, sum, tmp);
        return res;
    }
	
	void dfs(TreeNode * root, int sum, vector<int> & curr) {
	    if(root == NULL) return;
		if(root->left == NULL && root->right == NULL && root->val == sum) {
			curr.push_back(root->val);
			res.push_back(curr);
		} else {
			curr.push_back(root->val);
			dfs(root->left, sum - root->val, curr);
			curr.pop_back();
			dfs(root->right, sum - root->val, curr);
			
			curr.pop_back();
		}
	}
private:
	vector<vector<int>> res;
};