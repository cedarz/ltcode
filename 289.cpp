
const int loc[][2] = {
	{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
	{1, 0}, {1, -1}, {0, -1}, {-1, -1}
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
		if(row == 0) return;
		int col = board[0].size();
		
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				int live = 0;
				int dead = 0;
				for(int k = 0; k < 8; ++k) {
					int x = i + loc[k][0], y = j + loc[k][1];
					if(x < row && x >= 0 && y < col && y >= 0) {
						board[x][y] % 2 ? ++live : ++dead;
					}
				}
				if(board[i][j]) {
					if(live <= 1) {
						board[i][j] = 1;
					} else if(live == 2 || live == 3) {
						board[i][k] = 3;
					} else {
						board[i][j] = 1;
					}
				} else {
					if(live == 3) {
						board[i][j] = 2;
					}
				}
			}
		}
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				board[i][j] >>= 1;
			}
		}
    }
	
};

/*
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            int count = 0;
            for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                    count += board[I][J] & 1;
            if (count == 3 || count - board[i][j] == 3)
                board[i][j] |= 2;
        }
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            board[i][j] >>= 1;
}
*/