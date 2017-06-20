class Solution {
public:
    bool isPowerOfTwo(int n) {
		if(n <= 0) return false;
        int cnt_0 = 0;
		int cnt_1 = 0;
		while(n) {
			if(n % 2) {
				++cnt_1;
			} else {
				++cnt_0;
			}
			n /= 2;
		}
		return cnt_1 == 1;
    }
};