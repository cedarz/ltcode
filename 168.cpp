class Solution {
public:
	string convertToTitle(int n) {
		long long sum = 0;
		long long pw = 1;
		int cnt = 0;
		while(sum < n) {
			++cnt;
			sum += (pw *= 26);
		}
		pw = 1;
		sum = 0;
		for(int i = 0; i < cnt - 1; ++i) {
			sum += (pw *= 26);
		}
		n -= sum;
		//cout << n << " " << cnt << endl;
		
		string ret = "";
		--n;
		for(int i = 0; i < cnt; ++i) {
			ret += 'A' + (n % 26);
			n /= 26;
		}
		//cout << ret << endl;
		reverse(ret.begin(), ret.end());
		//cout << ret << endl;
		return ret;
	}
};