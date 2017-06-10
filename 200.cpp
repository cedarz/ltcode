class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
		int ret = 0;
		row = grid.size();
		col = grid[0].size();
		
        //while(true) {
			//bool to_bfs = false;
			for(int i = 0; i < row; ++i) {
				for(int j = 0; j < col; ++j) {
					if(grid[i][j] == '1') {
						++ret;
						//to_bfs = true;
						bfs(grid, i, j);
					}
				}
			}
			//if(!to_bfs) break;
		//}
		return ret;
    }
	
	void bfs(vector<vector<char>>& grid, int i, int j)  {
		queue<pair<int, int>> q;
		q.push(make_pair(i, j));
		grid[i][j] = '0';
		while(!q.empty()) {
			auto p = q.front();
			//grid[p->first][p->second] = '0';
			int x = p.first, y = p.second;
			q.pop();
			if(x - 1 >= 0 && grid[x - 1][y] == '1') {
				grid[x - 1][y] = '0';
				q.push(make_pair(x - 1, y));
			}
			if(x + 1 < row && grid[x + 1][y] == '1') {
				grid[x + 1][y] = '0';
				q.push(make_pair(x + 1, y));
			}
			if(y - 1 >= 0 && grid[x][y - 1] == '1') {
				grid[x][y - 1] = '0';
				q.push(make_pair(x, y - 1));
			}
			if(y + 1 < col && grid[x][y + 1] == '1') {
				grid[x][y + 1] = '0';
				q.push(make_pair(x, y + 1));
			}
		}
	}

private:
	int row, col;
};