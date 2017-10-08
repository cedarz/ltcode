class Solution {
public:
    int integerBreak(int n) {
        vector<int> f(n + 1, 0);
		f[2] = 1;
        f[1] = 1;
		for(int i = 3; i <= n; ++i) {
			for(int j = 1; j < i; ++j) {
				f[i] = max(f[i], max(j, f[j]) * max(i - j, f[i - j]));
			}
           // cout << i << " " << f[i] << endl;
		}
		return f[n];
    }
};