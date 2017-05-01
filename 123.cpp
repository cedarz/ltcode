class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int maxProt = 0;
		if(prices.empty()) return 0;
		
		int sz = prices.size();
		int k = 2;
		vector<vector<int>> mat(k + 1, vector<int>(sz, 0));
		
		for(int i = 1; i <= k; ++i) {
			int tmp_m = mat[i - 1][0] - prices[0];
			for(int j  = 1; j < sz; ++j) {
				mat[i][j] = std::max(mat[i][j - 1], tmp_m + prices[j]);
				tmp_m = std::max(tmp_m, mat[i - 1][j] - prices[j]);
				maxProt = std::max(maxProt, mat[i][j]);
			}
		}
		
		
		return maxProt;
    }
	
};