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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bt(nums, 0, nums.size() - 1);
    }
	
	TreeNode * bt(vector<int> & nums, int low, int high) {
		if(low == high) return new TreeNode(nums[low]);
		
		if(low > high) return NULL;
		
		int mid = (low + high) / 2;
		TreeNode * res = new TreeNode(nums[mid]);
		res->left = bt(nums, low, mid - 1);
		res->right = bt(nums, mid + 1, high);
		
		return res;
	}
};