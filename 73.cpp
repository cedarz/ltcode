class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int row = matrix.size();
        int rank = matrix[0].size();
        
        bool row0 = false;
        bool rank0 = false;
        
        if(matrix[0][0] == 0) {
            row0 = true;
            rank0 = true;
        } else {
            for(int i = 1; i < rank; ++i) {
                if(matrix[0][i] == 0) {
                    row0 = true;
                    break;
                }
            }
            for(int i = 1; i < row; ++i) {
                if(matrix[i][0] == 0) {
                    rank0 = true;
                    break;
                }
            }
        }
        
        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < rank; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < rank; ++i) {
            if(matrix[0][i] == 0) {
                sweep_rank(matrix, i, row);
            }
        }
        
        for(int i = 1; i < row; ++i) {
            if(matrix[i][0] == 0) {
                sweep_row(matrix, i, rank);
            }
        }
        
        if(row0) {
            for(int i = 0; i < rank; ++i) {
                matrix[0][i] = 0;
            }
        }
        
        if(rank0) {
            for(int i = 0; i < row; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
        
    void sweep_row(vector<vector<int>> & matrix, int row, int cnt) {
        for(int i = 1; i < cnt; ++i) {
            matrix[row][i] = 0;
        }
    }
    
    void sweep_rank(vector<vector<int>> & matrix, int rank, int cnt) {
        for(int i = 1; i < cnt; ++i) {
            matrix[i][rank] = 0;
        }
    }
};

