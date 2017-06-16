class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
		
		int row = matrix.size();
		int col = matrix[0].size();
		int res = 0;
		
		vector<vector<int>> dp(row, vector<int>(col, 0));
		
		for(int i = 0; i < row; ++i) {
			dp[i][col - 1] = matrix[i][col - 1] == '1' ? 1 : 0;
			for(int j = col - 2; j >= 0; --j) {
				dp[i][j] = matrix[i][j] == '1' ? dp[i][j + 1] + 1 : 0; // the longest width from left in i-th row
			}
		}
		
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				int wid = dp[i][j];
				for(int k = i; k < row; ++k) {
					wid = min(wid, dp[k][j]);
					int tmp = min(wid, k - i + 1);
					res = max(res, tmp * tmp);
				}
			}
		}
		return res;
    }
};