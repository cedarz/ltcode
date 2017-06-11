class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
		
		if(nums.size()  == 1) return nums[0];  // when the length is 1; edge sample
		// dp[0] ending with; dp[1] ending without
		vector<vector<int>> dp(2, vector<int>(nums.size(), 0)); 
		// leave last not robbed
		dp[0][0] = nums[0];
		dp[1][0] = 0;
		const int Len = nums.size();
		for(int i = 1; i < Len; ++i) {
			dp[0][i] = dp[1][i - 1] + nums[i];
			dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
		}
		int res1 = dp[1][Len - 1];
		
		// last robbed
		dp[0][0] = 0;
		dp[1][0] = 0;
		for(int i = 1; i < Len; ++i) {
			dp[0][i] = dp[1][i - 1] + nums[i];
			dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
		}
		int res2 = dp[0][Len - 1];
		
		return max(res1, res2);
    }
};

// https://discuss.leetcode.com/topic/14504/9-lines-0ms-o-1-space-c-solution
/* 
This problem is a little tricky at first glance. However, if you have finished the House Robber problem, this problem can simply be decomposed into two House Robber problems.
Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of

1. Rob houses 0 to n - 2;
2. Rob houses 1 to n - 1.
The code is as follows. Some edge cases (n < 2) are handled explicitly.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
*/