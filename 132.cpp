class Solution {
public:
    int minCut(string s) {
        if(s.empty()) return 0;
		
		int len = s.size();
		vector<vector<int>> f(len, vector<int>(len, 0));
		vector<int> ans(len + 1, 0);
		for(int i = 0; i <= len; ++i) ans[i] = len - 1 - i;
		
		
		return dp(f, len, s, ans);	
    }
	
	bool is_palindrome(const string & s) {
		int low = 0, high = s.size() - 1;
		while(low <= high && s[low] == s[high]) {
			++low;
			--high;
		}
		if(low <= high) return false;
		else return true;
	}
	int dp(vector<vector<int>> & f, int len, string & s, vector<int> & ans) {
		for(int i = len - 1; i >= 0; --i) {
			for(int j = i; j < len; ++j) {
				//f[i][j] = j - i; //cut num
				//if(is_palindrome(s.substr(i, j - i + 1))) {
				//	f[i][j] = 0;
				//	continue;
				//}
				//for(int k = i; k < j; ++k) {
				//	f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + 1);
				//}
				if(i == j) f[i][j] = 1;
				if(s[i] == s[j]) {
					if(i == j - 1) f[i][j] = 1;
					else f[i][j] = f[i + 1][j - 1];
				}
			}
		}
		for(int i = len - 1; i >= 0; --i) {
			if(f[i][len - 1] == 1) {
				ans[i] = 0;
				continue;
			}
			for(int j = i; j < len; ++j)  {
				if(f[i][j] == 1) {
					ans[i] = min(ans[i], ans[j + 1] + 1);
				}
			}
		}
		return ans[0];
	}
};