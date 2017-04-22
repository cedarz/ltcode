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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return bt(inorder, postorder, 0, 0, postorder.size());
    }
	
	TreeNode * bt(vector<int> & inorder, vector<int> & postorder, int ino, int post, int sz) {
		if(sz == 0) return NULL;
		else if(sz == 1) return new TreeNode(postorder[post]);
		else {
			int loc = ino;
			for(int i = 0; i < sz; ++i) {
				if(inorder[ino + i] == postorder[post + sz - 1]) {
					loc = ino + i;
					break;
				}
			}
			TreeNode * res = new TreeNode(postorder[post + sz - 1]);
			res->left = bt(inorder, postorder, ino, post, loc - ino);
			res->right = bt(inorder, postorder, loc + 1, post + loc - ino, sz - 1 - loc + ino);
			return res;
		}
	}
};