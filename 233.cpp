#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
		if(n <= 0) return 0;
		long long m[12];
		m[0] = 0;
		for(int i = 1, p = 1; i < 12; ++i, p *= 10) {
			m[i] = i * p;
		}
		
		long long mi = 1;
		int cnt = 0;
		while(mi * 10 <= n) {
			mi *= 10;
			++cnt;
		}
		
		int res = 0;
		while(n) {
			if(cnt == 0) {
				res += n >= 1 ? 1 : 0;
				break;
			}
			int tmp = n / mi;
			if(tmp > 1) {
				res += mi + tmp * m[cnt];
			} else if(tmp == 1) {
				res += m[cnt] + n - mi + 1;
			}
			n -= tmp * mi;
			mi /= 10;
			--cnt;
		}
		return res;
    }
	
	int test(int k) {
		//for(int k = 10; k <= 100000; k *= 10) {
			int cnt = 0;
			for(int i = 0; i <= k; ++i) {
				int tmp = i;
				while(tmp) {
					if(tmp % 10 == 1) ++cnt;
					tmp /= 10;
				}
			}
			//cout << k << " " << cnt << endl;
		//}
		return cnt;
	}
};

int main() {
	Solution sol;
	cout << sol.countDigitOne(10) << " " << sol.test(10) << endl;
	cout << sol.countDigitOne(1410065408) << endl;;
	
	return 0;
}

/*
10 1
100 20
1000 300
10000 4000
100000 50000
*/
