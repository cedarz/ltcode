class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int L = nums.size();
		int loc = 0;
		for(int i = 0; i < L; ++i) {
			if(nums[i] != 0) {
				nums[loc++] = nums[i];
			}
		}
		for(int i = loc; i < L; ++i) {
			nums[i] = 0;
		}
    }
};