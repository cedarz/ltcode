/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode * iter = root;
		while(iter) {
			stk.push(iter);
			iter = iter->left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
		assert(hasNext());
        TreeNode * tmp = stk.top();
		stk.pop();
		if(tmp->right) {
			stk.push(tmp->right);
			TreeNode * iter = tmp->right;
			while(iter) {
				stk.push(iter);
				iter = iter->left;
			}
		}
		return tmp->val;
    }
private:
	stack<TreeNode *> stk;
	
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */