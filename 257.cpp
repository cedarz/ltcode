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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return vector<string>();
		
		string path(to_string(root->val));
		btp(root, path);
		
		return vs;
    }
	
	void btp(TreeNode * root, string & p) {
		string tmp(p);
		if(root->left == nullptr && root->right == nullptr) {
			vs.push_back(p);
		} 
		if(root->left) {
			p += "->" + to_string(root->left->val);
			btp(root->left, p);
			p = tmp;
		}
		if(root->right) {
			p += "->" + to_string(root->right->val);
			btp(root->right, p);
			p =tmp;
		}
	}
private:
	vector<string> vs;
};