class Solution {
public:
    int candy(vector<int>& ratings) {
		if(ratings.empty()) return 0;
		
		ratings.push_back(0xfffffff);
		const int Len = ratings.size();
        vector<int> mat(Len, 0);
		
		// dp
		mat[0] = 1;
		for(int i = 1; i < Len; ++i) {
			if(ratings[i] > ratings[i - 1]) {
				mat[i] = mat[i - 1] + 1;
				if(i - 1 > 0 && ratings[i - 1] < ratings[i - 2]) {
					int k = i - 1, candy = 1;
					for(; ratings[k] < ratings[k - 1] && k >= 0; --k) {
						mat[k] = candy++;
					}
					if(mat[k] <= mat[k + 1]) mat[k] = candy;
					mat[i] = mat[i - 1] + 1;
				}
			} else if(ratings[i] == ratings[i - 1]) {
				mat[i] = 1;
				if(i - 1 > 0 && ratings[i - 1] < ratings[i - 2]) {
					int k = i - 1, candy = 1;
					for(; ratings[k] < ratings[k - 1] && k >= 0; --k) {
						mat[k] = candy++;
					}
					if(mat[k] <= mat[k + 1]) mat[k] = candy;
				}
			} else {
				mat[i] = ratings[i - 1] - 1;
			}
		}
		int tmp = 0; 
		for(int i = 0; i < Len - 1; ++i) {
		    cout << mat[i] << " ";
			tmp += mat[i];
		}
		cout << endl;
		return tmp;
    }
};