// https://discuss.leetcode.com/topic/37281/clean-and-short-with-comments-c
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
		int first = nums[0];
		int second = INT_MAX;
		for(int i = 1; i < nums.size(); ++i) {
			if(nums[i] <= first) {
				first = nums[i];
			} else if(nums[i] <= second) {
				second = nums[i];
			} else {
				return true;
			}
		}
		return false;
    }
};