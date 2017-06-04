#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt_2 = 0;
		for(int pw = 2; pw <= n; pw *= 2) {
			cnt_2 += (n / pw);
		}
		int cnt_5 = 0;
		for(int pw = 5; pw <= n; pw *= 5) {
			cnt_5 += (n / pw);
		}
	
		return min(cnt_2, cnt_5);
    }
};
