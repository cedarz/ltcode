class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //hash_map<int, int> hm;
		int miss = 1; // 缺少最小的数
		int add = 0;
		int i = 0;
		while(miss <= n) {
			if(nums[i] < miss) {
				miss += nums[i++];
				++add;
			} else {
				miss += miss;
			}
		}
		return add;
    }
};

// https://leetcode.com/problems/patching-array/discuss/