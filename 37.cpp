int r1[9][9] = {0};
int c1[9][9] = {0};
int rc3[3][3][9] = {0};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(r1, 0, sizeof(r1));
        memset(c1, 0, sizeof(c1));
        memset(rc3, 0, sizeof(rc3));
        isValidSudoku(board);
        int cnt = 0;
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') ++cnt;
            }
        }
        dfs(board, cnt);
    }
    
    bool dfs(vector<vector<char> > & board, int k) {
        //cout << "K == " << k << endl;
        if(k == 0) return true;
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    for(int guess = 1; guess <= 9; ++guess) {
                        board[i][j] = guess + '0';
                        r1[i][guess - 1]++;
                        c1[j][guess - 1]++;
                        rc3[i / 3][j / 3][guess - 1]++;
                        if(r1[i][guess - 1] > 1 || c1[j][guess - 1] > 1 || rc3[i/3][j/3][guess - 1] > 1 || !dfs(board, k - 1)) {
                            board[i][j] = '.';
                            r1[i][guess - 1]--;
                            c1[j][guess - 1]--;
                            rc3[i / 3][j / 3][guess - 1]--;
                            continue;
                        } 
                        return true;
                    }
                    return false;
                }
            }
        }   
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //memset(r1, 0, sizeof(r1));
        //memset(c1, 0, sizeof(c1));
        //memset(rc3, 0, sizeof(rc3));
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                int tmp = board[i][j] - '0' - 1;
                if(tmp <= 8 && tmp >= 0) {
                    r1[i][tmp]++;
                    c1[j][tmp]++;
                    rc3[i / 3][j / 3][tmp]++;
                    if(r1[i][tmp] > 1 || c1[j][tmp] > 1 || rc3[i/3][j/3][tmp] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

