class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
		vector<bool> v(n + 1, true);
		for(int i = 2; i <= n; ++i) {
			if(v[i]) {
				for(int k = i; k <= n; k += i) {
					v[k] = false;
				}
			}
		} 
		int cnt = 0;
		for(int i = 2; i <= n; ++i) {
			if(v[i]) ++cnt;
		}
		return cnt;
    }
};