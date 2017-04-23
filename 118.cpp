class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
		if(numRows == 0) return res;
		vector<int> tmp;
		tmp.push_back(1);
		res.push_back(tmp);
		
		if(numRows >= 2) {
			for(int i = 2; i <= numRows; ++i) {
				vector<int> & row = res[i - 2];
				vector<int> curr;
				for(int k = 0; k < i; ++k) {
					if(k == 0 || k == i - 1) curr.push_back(1);
					else {
						curr.push_back(row[k - 1] + row[k]);
					}
				}
				res.push_back(curr);
			}
		}
		return res;
		
    }
};