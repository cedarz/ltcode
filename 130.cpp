class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
		
		int row = board.size(), col = board[0].size();
		
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(board[i][j] == 'O' && is_open(i, j, row, col)) {
					bfs(board, i, j, row, col);
				}
			}
		}
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(board[i][j] == 'O') {
					board[i][j] = 'X';
				} else if(board[i][j] == 'B') {
				    board[i][j] = 'O';
				}
			}
		}
    }
	
	bool is_open(int r, int c, int row, int col) {
		return r - 1 < 0 || r + 1 >= row || c - 1 < 0 || c + 1 >= col;
	}
	
	void dfs(vector<vector<char>> & board, int r, int c, int row, int col) {
		//cout << r << " " << c << endl;
		board[r][c] = 'B';
		if(r - 1 >= 0 && board[r - 1][c] == 'O') dfs(board, r - 1, c, row, col);
		if(r + 1 < row && board[r + 1][c] == 'O') dfs(board, r + 1, c, row, col);
		if(c - 1 >= 0 && board[r][c - 1] == 'O') dfs(board, r, c - 1, row, col);
		if(c + 1 < col && board[r][c + 1] == 'O') dfs(board, r, c + 1, row, col);
	}
	
	void bfs(vector<vector<char>> & mat, int r, int c, int row, int col) {
		q.push(make_pair(r, c));
		mat[r][c] = 'B';
		while(!q.empty()) {
		    pair<int, int> pr = q.front();
			int x = pr.first, y = pr.second;
			//cout << x << " " << y << " " << mat[x][y] << endl;
			q.pop();
			if(x - 1 >= 0 && x - 1 < row && y >= 0 && y < col && mat[x - 1][y] == 'O') {
				mat[x - 1][y] = 'B';  //把=写成了==
				q.push(make_pair(x - 1, y));
			}
			if(x + 1 >= 0 && x + 1 < row && y >= 0 && y < col && mat[x + 1][y] == 'O') {
				mat[x + 1][y] = 'B';
				q.push(make_pair(x + 1, y));
			} 
			if(y - 1 >= 0 && y - 1 < col && x >= 0 && x < row && mat[x][y - 1] == 'O') {
				mat[x][y - 1] = 'B';
				q.push(make_pair(x, y - 1));
			}
			if(y + 1 >= 0 && y + 1 < col && x >= 0 && x < row && mat[x][y + 1] == 'O') {
				mat[x][y + 1] = 'B';
				q.push(make_pair(x, y + 1));
			}
			/*
			pair<int, int> cur = q.front();
            q.pop();
            pair<int, int> adjs[4] = {  {cur.first-1, cur.second}, 
                                        {cur.first+1, cur.second}, 
                                        {cur.first, cur.second-1},
                                        {cur.first, cur.second+1}};
            for (int i = 0; i < 4; ++i) {
                int adjW = adjs[i].first;
                int adjL = adjs[i].second;
                if ((adjW >= 0) && (adjW < row) && (adjL >= 0)&& (adjL < col) 
								&& (mat[adjW][adjL] == 'O')) {
                    q.push(make_pair(adjW, adjL));
                    mat[adjW][adjL] = 'B';
                }
            }
			*/
    	}
	}
private:
	//vector<vector<char>> m;
	queue<pair<int, int>> q;
};