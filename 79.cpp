
int dir[][2] = {1, 0,
                0, 1,
                -1, 0,
                0, -1};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        lx = board.size();
        ly = board[0].size();
        sz = word.size();
        for(int i = 0; i < lx; ++i) {
            for(int j = 0; j < ly; ++j) {
                if(board[i][j] == word[0]) {
                    x = i, y = j;
                    vector<vector<int>> v(lx, vector<int>(ly, 0));
                    v[x][y] = 1;
                    if(dfs(board, v, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    int lx, ly; // board size
    int x, y;
    int sz;
    bool is_valid(int vi, int vj) {
        return (vi < lx && vi >= 0) && (vj < ly && vj >= 0);
    }
    bool dfs(vector<vector<char>> & board, vector<vector<int>> & visited, 
            string & word, int k) {
        //cout << x << " " << y << " " << k << endl;
        if(k == sz - 1) return true;
        else {
            for(int i = 0; i < 4; ++i) {
                int tx = x + dir[i][0];
                int ty = y + dir[i][1];
                if(is_valid(tx, ty) && visited[tx][ty] == 0 && board[tx][ty] == word[k + 1]) {
                    visited[tx][ty] = 1;
                    x = tx, y = ty;
                    if(dfs(board, visited, word, k + 1)) {
                        return true;
                    }
                    visited[tx][ty] = 0;
                    x -= dir[i][0], y -= dir[i][1];
                }
            }
            return false;
        }
    }
};


