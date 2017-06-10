class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
		
		// dp[0] ending with; dp[1] ending without
		vector<vector<int>> dp(2, vector<int>(nums.size(), 0)); 
		dp[0][0] = nums[0];
		dp[1][0] = 0;
		const int Len = nums.size();
		for(int i = 1; i < Len; ++1) {
			dp[0][i] = dp[1][i] + nums[i];
			dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
		}
		return max(dp[0][Len - 1], dp[1][Len - 1]);
    }
};