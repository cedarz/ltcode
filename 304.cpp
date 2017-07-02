class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int row = matrix.size();
		int col = row == 0 ? 0 : matrix[0].size();
		
		for(int i = 0; i < row; ++i) {
			vector<int> tmp;
			int sum_line = 0;
			for(int j = 0; j < col; ++j) {
				sum_line += matrix[i][j];
				tmp.push_back(sum_line + (i == 0 ? 0 : res[i - 1][j]));
			}
			res.push_back(tmp);
		}
        for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				cout << res[i][j] << " ";
			}
            cout << endl;
		}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        --row1, -- col1, --row2, --col2;
		cout << res[row2][col2] << endl;
		return res[row2][col2] - (row1 == 0 ? 0 : res[row1 - 1][col2]) - (col1 == 0 ? 0 : res[row2][col1 - 1]) + 
			(row1 == 0 || col1 == 0 ? 0 : res[row1 - 1][col1 - 1]);
    }
	
private:
	vector<vector<int>> res;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */