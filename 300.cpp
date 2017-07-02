class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int L = nums.size();
		if(L <= 1) return L;
		
        vector<int> lis(L, 1);
		for(int i = 1; i < L; ++i) {
			for(int j = 0; j < i; ++j) {
				if(nums[i] > nums[j]) {
					lis[i] = max(lis[i], lis[j] + 1);
				}
			}
		}
		int res = 0;
		for(int i = 0; i < L; ++i) {
			res = std::max(res, lis[i]);
		}
		return res;
    }
};