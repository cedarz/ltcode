class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.empty() || matrix[0].empty()) return false;
		if(matrix.back().back() < target) return false;
		
        for(int i = 0; i < matrix.size(); ++i) {
			if(matrix[i][0] > target) return false;
			if(bs(matrix, i, target)) return true;
		}
		return false;
    }
	
	bool bs(vector<vector<int>> & matrix, int row, int target) {
		if(target < matrix[row][0] || target > matrix[row].back()) return false;
		
		int low = 0, high = matrix[0].size() - 1;
		int mid = (low + high) / 2;
		
		while(low <= high) {
			mid = (low + high) / 2;
			if(matrix[row][mid] == target) {
				return true;
			} else if(matrix[row][mid] < target) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return false;
	}
};