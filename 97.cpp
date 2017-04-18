class Solution {
public:
    bool isInterleave_wrong(string s1, string s2, string s3) {
        int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		
		if (len1 + len2 != len3) return false;
		
		bool flag = false;
		
		int i = 0, j = 0, k = 0;

		while(k < len3) {
			bool changed = false;
			while(s1[i] == s3[k]) {
				changed = true;
				++i;
				++k;
			}
			while(s2[j] == s3[k]) {
				changed = true;
				++j;
				++k;
			}
			if(!changed) break;
		}
		if(k == len3) return true;
    }
	
	bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		
		if(len1 + len2 != len3) return false;
		
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		
		dp[0][0] = 1;
		for(int i = 1; i <= len1; ++i) {
			dp[i][0] = s1.substr(0, i) == s3.substr(0, i) ? 1 : 0;
		}
		for(int i = 1; i <= len2; ++i) {
			dp[0][i] = s2.substr(0, i) == s3.substr(0, i) ? 1 : 0;
		}
		
		for(int i = 1; i <= len1; ++i) {
			for(int j = 1; j <= len2; ++j) {
				if(s1[i - 1] == s3[i + j - 1]) dp[i][j] |= dp[i - 1][j];
				if(s2[j - 1] == s3[i + j - 1]) dp[i][j] |= dp[i][j - 1];
				//cout << dp[i][j] << " ";
			}
			//cout << endl;
		}
		return dp[len1][len2];
	}
};










