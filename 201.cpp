class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		vector<int> v;
        while(true) {
			if(m == 0 && n == 0) break;
			if(m - n + 1 >= 2) v.push_back(0);
			else v.push_back(1);
			
			n >>= 1;
			m >>= 1;
		}
		
		int ret = 0;
		for(int i = v.size() - 1; i >= 0; --i) {
			ret = (ret << 1) + v[i];
		}
		return ret;
    }
	
	int rangeBitwiseAnd_(int m, int n) {
		int c = 0;
		while(n != m) {
			++c;
			m >>= 1;
			n >>= 1;
		}
		return n << c;
	}
};