class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size(); 
		
		vector<int> dp_max(len, 0); // max when ending at i : dp_max[i]
		vector<int> dp_min(len, 0);
		
		dp_max[0] = nums[0];
		dp_min[0] = nums[0];
		int res = dp_max[0];
		
		for(int i = 1; i < len; ++i) {
			dp_max[i] = max(nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
			dp_min[i] = min(nums[i], min(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]));
			res = max(res, dp_max[i]);
		}
		
		return res;	
		
    }
};