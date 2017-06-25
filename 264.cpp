#include <iostream>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
		int test = 1;
		int cnt = 1;
		int i = 0, j = 0, k = 0;
		
		if(n <= 0) return 0;
		
		vector<int> v(n, 0);
		v[0] = 1;
		
		for(int cnt = 1; cnt < n; ++cnt) {
			int tmp = min(min(v[i] * 2, v[j] * 3), v[k] * 5);
			if(tmp == v[i] * 2) ++i;
			if(tmp == v[j] * 3) ++j;
			if(tmp == v[k] * 5) ++k;
			
			v[cnt] = tmp;
		}
		return v[n - 1];
    }

};
/* https://discuss.leetcode.com/topic/21791/o-n-java-solution /*
