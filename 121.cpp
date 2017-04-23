class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
		if(prices.empty()) return 0;
		int min_p = prices[0];
		int sz = prices.size();
		for(int i = 1; i < sz; ++i) {
			min_p = min(min_p, prices[i - 1]);
			res = max(res, prices[i] - min_p);
		}
		return res;
    }
};