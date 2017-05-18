class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char, vector<string>> m;
		for(int i = 0; i < wordDict.size(); ++i) {
			m[wordDict[i][0]].push_back(wordDict[i]);
		}
		return dfs(s, m);
    }
	
	bool dfs(string & s, unordered_map<char, vector<string>> & m) {
		if(s == "") return true;
		
		char ch = s[0];
		vector<string> & vs = m[ch];
		for(int i = 0; i < vs.size(); ++i) {
			int len = vs[i].size();
			if(s.substr(0, len) == vs[i]) {
				string tmp = s.substr(len);
				if(dfs(tmp, m)) return true;
			}
		}
		return false;
	}
};