class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() < 2) return 0;
		
		k = min(k, int(prices.size() - 1));
		//vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 00));
		vector<int> dp1(prices.size(), 0);
		vector<int> dp2(prices.size(), 0);
		
		int ret = 0;
		//dp[i][j] = max{dp[i][j - 1], max{dp[i - 1][w] + prices[i] - prices[w]}(0 < w < i) }
		for(int i = 1; i <= k; ++i) {
			int tmp_max = dp1[0] - prices[0];
			for(int j = 1; j < prices.size(); ++j) {
				dp2[j] = std::max(dp2[j - 1], tmp_max + prices[j]);
				tmp_max = std::max(tmp_max, dp1[j] - prices[j]);
				ret = std::max(ret, dp2[j]);
			}
			swap(dp1, dp2);
		}
		return ret;
    }
};