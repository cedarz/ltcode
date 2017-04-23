class Solution {
public:
    vector<int> getRow(int rowIndex) {
		//int k = 1;
		//int n = 1;
		vector<int> res;
        for(int i = 0; i <= rowIndex; ++i) {
			if(i == 0) res.push_back(1);
			else if(i <= rowIndex / 2) {
				//k *= i;
				//n *= n - i + 1;
				//cout << n << " " << k << " " << n / k << endl;
				//res.push_back(n / k);
				long long tmp = (long long)(res[i - 1]) * (rowIndex - i + 1) / i;
				res.push_back(tmp);
			} else {
				res.push_back(res[rowIndex - i]);
			}
		}
		return res;
    }
};