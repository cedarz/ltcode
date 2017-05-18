class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m;
		for(int i = 0; i < wordDict.size(); ++i) {
			m.insert(wordDict[i]);
		}
		return dfs(s, m);
    }
	
	bool dfs(string & s, unordered_set<string> & m) {
		const int Len = s.size();
		vector<vector<bool>> vb(Len, vector<bool>(Len, false));
		for(int i = 0; i < Len; ++i) {
			if(m.find(string(1, s[i])) != m.end()) {
				vb[i][i] = true;
			}
		}
		
		for(int i = Len - 1; i >= 0; --i) {
			for(int j = i; j < Len; ++j) {
				for(int k = i; k < j; ++k) {
					if(vb[i][k] && vb[k + 1][j]) {
						vb[i][j] = true;
						break;
					}
				}
				vb[i][j] = vb[i][j] || m.find(s.substr(i, j - i + 1)) != m.end();
			}
		}
		return vb[0][Len - 1];
		
	}
};