class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> w;
		for(int i = 1; i < prices.size(); ++i) {
			w.push_back(prices[i] - prices[i - 1]);
		}
		
		vector<int> dp(w);
		int res = 0;
		
		// 居然dp对了，对相邻元素差作dp，某一段可以连续，如果分割的必须序号差>=3
		for(int i = 0; i < w.size(); ++i) {
			int tmp = dp[i];
			for(int j = 0; j <= i - 3; ++j) {
				dp[i] = max(dp[i], dp[j] + tmp);
			}
			if(i >= 1) dp[i] = max(dp[i], dp[i - 1] + tmp);
			res = max(dp[i], res);
		}
		return res;
    }
};