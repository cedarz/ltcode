class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int L = nums.size();
		vector<int> left(L, 1);
		vector<int> right(L, 1);
		
		for(int i = 1; i < L; ++i) {
			left[i] = left[i - 1] * nums[i - 1];
		}
		for(int i = L - 2; i >= 0; --i) {
			right[i] = right[i + 1] * nums[i + 1];
		}
		
		for(int i = 0; i < L; ++i) {
			left[i] *= right[i];
		}
		return left;
    }
};