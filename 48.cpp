class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        tranpose(matrix);
        flip_left_right(matrix);
    }
    
    void tranpose(vector<vector<int>> & matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void flip_left_right(vector<vector<int>> & matrix) {
        int n = matrix.size();
        for(int k = 0; k < n; ++k) { 
            for(int i = 0, j = n - 1; i < j; ++i, --j) {
                swap(matrix[k][i], matrix[k][j]);
            }
        }
    }
};

