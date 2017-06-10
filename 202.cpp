class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
		s.insert(n);
		int tmp = n;
		while(true) {
			tmp = _to_square(tmp);
			if(tmp == 1) return true;
			if(s.find(tmp) != s.end()) {
				return false;
			} else {
				s.insert(tmp);
			}
		}
    }
	
	int _to_square(int n) {
		int sum = 0;
		while(n) {
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		return sum;
	}
};