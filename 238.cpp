class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int L = nums.size();
		vector<int> ans(L, 1);
		for(int i = 0; i < L; ++i) {
			for(int j = 0; j < L; ++j) {
				if(i == j) continue;
				else ans[j] *= nums[i];
			}
		}
		return ans;
    }
};