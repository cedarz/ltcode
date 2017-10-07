#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// https://discuss.leetcode.com/topic/35063/c-dp-dfs-solution-sharing
static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        rows = matrix.size();
		if(rows == 0) return 0;
		cols = matrix[0].size();
		
		vector<vector<int> > m(rows, vector<int>(cols, 0));
		
		int ret = 0; 
		for(int i = 0; i < rows; ++i) {
			for(int j = 0; j < cols; ++j) {
				//cout << i << " " << j << endl;
				ret = max(ret, dfs(matrix, m, i, j));
			}
		}
		return ret;
    }
	
	int dfs(vector<vector<int> > & matrix, vector<vector<int> > & dp, int i, int j) {
		if(dp[i][j]) return dp[i][j];
		for(int k = 0; k < 4; ++k) {
			int x = i + dirs[k][0];
			int y = j + dirs[k][1];
			if(x < 0 || x >= rows || y < 0 || y >= cols) continue;
			if(matrix[x][y] <= matrix[i][j]) continue;
			dp[i][j] = max(dp[i][j], dfs(matrix, dp, x, y));
		}
		++dp[i][j];
		//cout << dp[i][j] << endl;
		return dp[i][j];
	}
	
private:
	
	int rows, cols;
};

int main() {
	vector<vector<int> > m{{9,9,4},{6,6,8},{2,1,1}};
	cout << Solution().longestIncreasingPath(m) << endl;
	
	return 0;
}
