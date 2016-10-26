int dp[101][101];

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, 0, sizeof(dp));
        int m = obstacleGrid.size();
        if(0 == m) return 0;
        int n = obstacleGrid[0].size();

        for(int i = 1; i <= m && obstacleGrid[i - 1][0] == 0; ++i) {
            dp[i][1] = 1;
        }
        for(int j = 1; j <= n && obstacleGrid[0][j - 1] == 0; ++j) {
            dp[1][j] = 1;
        }
        for(int i = 2; i <= m; ++i) {
            for(int j = 2; j <= n; ++j) {
                if(obstacleGrid[i - 1][j - 1] == 0) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = 0;
                }
            }
        }     
        return dp[m][n];
    }
};


