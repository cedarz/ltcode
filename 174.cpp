class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
		int col = dungeon[0].size();
		
		//dp[i][j] : how much needed at least at(i, j)
		vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
		dp[row - 1][col - 1] = dungeon[row - 1][col - 1] > 0 ? 1 : 1 - dungeon[row - 1][col - 1];
		
		for(int i = row - 1; i >= 0; --i) {
			for(int j = col - 1; j >= 0; --j) {
				if(j < col - 1) {
					if(dungeon[i][j] >= dp[i][j + 1]) {
						dp[i][j] = min(1, dp[i][j]);
					} else {
						dp[i][j] = min(dp[i][j + 1] - dungeon[i][j + 1], dp[i][j]);
					}
				}
				if(i >= 1) {
					if(dungeon[i - 1][j] >= dp[i][j]) {
						dp[i - 1][j] = min(1, dp[i - 1][j]);
					} else {
						dp[i - 1][j] = min(dp[i][j] - dungeon[i - 1][j], dp[i - 1][j]);
					}
				}
			}
		}
		return dp[0][0];
    }
};