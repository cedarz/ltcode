class Solution {
public:

	//对称
    vector<int> grayCode(int n) {
		if(n == 0) return vector<int>(1, 0);
        vector<int> res;
		res.push_back(0);
		res.push_back(1);
		int tmp = 1;
		
		for(int i = 1; i < n; ++i) {
			tmp *= 2;
			for(int j = tmp - 1; j >= 0; --j) {
				res.push_back(tmp + res[j]);
			}
		}
		return res;
    }
};