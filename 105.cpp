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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bt(preorder, inorder, 0, 0, preorder.size());
    }
	
	// pre : the first place of preorder
	// ino : the first place of inorder
	// sz  : the size of the current list
	TreeNode * bt(vector<int> & preorder, vector<int> & inorder, int pre, int ino, int sz) {
		if(sz == 0) return NULL;
		
		else if(sz == 1) return new TreeNode(preorder[pre]);
		
		else {
			int loc = ino;
			for(int i = 0; i < sz; ++i) {
				if(inorder[ino + i] == preorder[pre]) {
					loc = ino + i;
					break;
				}
			}
			TreeNode * res = new TreeNode(preorder[pre]);
			cout << loc - ino << " " << sz - 1 - loc + ino << endl;
			res->left = bt(preorder, inorder, pre + 1, ino, loc - ino);
			res->right = bt(preorder, inorder, pre + 1 + loc - ino, loc + 1, sz - 1 - loc + ino);
			return res;
		}
		
	}
};