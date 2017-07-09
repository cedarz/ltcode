#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        sort(primes.begin(), primes.end());
		
		vector<int> dp(n, 0);
		vector<int> cnt(primes.size(), 0);
		dp[0] = 1;
		
		for(int i = 1; i < n; ++i) {
			int tmp = INT_MAX;
			for(int c = 0; c < primes.size(); ++c) {
				tmp = min(tmp, dp[cnt[c]] * primes[c]);
			}
			for(int c = 0; c < primes.size(); ++c) {
				if(tmp == dp[cnt[c]] * primes[c]) ++cnt[c];
			}
			dp[i] = tmp;
			
			cout << dp[i] << endl;
		}
		return dp[n - 1];
    }
};

int main() {
	vector<int> p = {2,7,13,19};
	Solution sol;
	sol.nthSuperUglyNumber(12, p);
	
	return 0;
}
