
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int res = 0;
        if(grid.empty()) return 0;
        int row = grid.size(), rank = grid[0].size();
        
        vector<vector<int> > dp(row, vector<int>(rank, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < row; ++i) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < rank; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < rank; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][rank - 1];
    }
};

int main() {
    Solution s;
    
    return 0;
}