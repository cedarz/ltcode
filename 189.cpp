class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end() - k);
		reverse(nus.end() - k, nums.end());
		reverse(nums.begin(), nums.end());
    }
};