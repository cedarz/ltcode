int r1[9][9] = {0};
int c1[9][9] = {0};
int rc3[3][3][9] = {0};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
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

