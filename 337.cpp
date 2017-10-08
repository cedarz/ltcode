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
    // https://discuss.leetcode.com/topic/39659/easy-understanding-solution-with-dfs
	int rob(TreeNode * root) {
		pair<int, int> res = dfs(root);
		return max(res.first, res.second);
	}
	
	pair<int, int> dfs(TreeNode * root) {
		if(root == nullptr) {
			return pair<int, int>(0, 0);
		}
		// has - has not
		pair<int, int> left = dfs(root->left);
		pair<int, int> right = dfs(root->right);
		pair<int, int> res = make_pair(root->val + left.second + right.second, 
			max(left.first, left.second) + max(right.first, right.second));
		return res;
	}
    int rob_wrong(TreeNode* root) {
		if(root == nullptr) return 0;
        vector<int> level;
		bfs(root, level);
		const int Len = level.size();
		vector<int> yes(level.size() + 1, 0);
		vector<int> no(level.size() + 1, 0);
		for(int i = 1; i <= level.size(); ++i) {
			yes[i] = no[i - 1] + level[i - 1];
			no[i] = max(yes[i - 1], no[i - 1]);
		}
		return max(yes[Len], no[Len]);
    }
	
	void bfs(TreeNode * root, vector<int> & level) {
		vector<TreeNode * > first;
		if(root) first.push_back(root);
		while(!first.empty()) {
			int sum = 0;
			vector<TreeNode *> tmp;
			for(auto node : first) {
				sum += node->val;
				if(node->left) tmp.push_back(node->left);
				if(node->right) tmp.push_back(node->right);
			}
			level.push_back(sum);
			first.swap(tmp);
		}
		reverse(level.begin(), level.end());
	}
};