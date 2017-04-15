
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
		row = matrix.size();
		col = matrix[0].size();
		
		return dp(matrix);
    }
	
	//dp[i][j] gives the width of the rectangle with matrix[i][j] as the top-left cornor
	int dp(vector<vector<char>>& matrix) {
		vector<vector<int>> dp(row, vector<int>(col, 0));
		int res = 0;
		
		for(int i = 0; i < row; ++i) {
			//for(int j = 0; j < col; ++j) {
			//	dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
			//}
			dp[i][col - 1] = matrix[i][col - 1] == '1' ? 1 : 0;
			for(int j = col - 2; j >= 0; --j) {
				dp[i][j] = matrix[i][j] == '1' ? dp[i][j + 1] + 1 : 0;
			}
		}
		
		for(int i = 0 ; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				int width = col;
				for(int k = i; k < row; ++k) {
					if(dp[k][j] == 0) break;
					else {
						width = std::min(width, dp[k][j]);
						res = std::max(res, width * (k - i + 1));
					}
				}
			}
		}
		return res;
	}
	
private:
	int row, col;
};