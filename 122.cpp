class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
		
		int sz = prices.size();
		for(int i = 0; i < sz - 1; ++i) {
			res += max(prices[i + 1] - prices[i], 0); //multiple
		}
		return res;
    }
};