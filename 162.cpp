class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		const int L = nums.size();
        nums.push_back(INT_MIN);
		
		for(int i = 0; i < L; ++i) {
			if(i == 0) {
				if(nums[i] > nums[i + 1]) return i;
			} else {
				if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
					return i;
				}
			}
		}
    }
};