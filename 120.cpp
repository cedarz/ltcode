class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        vector<int> res = triangle.back();
		
		int sz = triangle.size();
		for(int i = sz - 2; i >= 0; --i) {
			for(int j = 0; j <= i; ++j) {
				res[j] = min(res[j], res[j + 1]) + triangle[i][j];
			}
		}
		return res[0];
    }
};