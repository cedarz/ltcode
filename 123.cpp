class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
		
		int sz = prices.size();
		vector<vector<int>> mat(sz, vector<int>(sz, 0));
		
		for(int i = sz - 1; i >= 0; --i) {
			for(int j = i + 1; j < sz; ++j) {
				
			}
		}
		return res;
    }
};