class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char, vector<string>> m;
		for(int i = 0; i < wordDict.size(); ++i) {
			m[wordDict[i][0]].push_back(wordDict[i]);
		}
		string ws("");
		dfs(s, m, ws);
		return ret;
    }
	
	void dfs(string & s, unordered_map<char, vector<string>> & m, string & ws) {
		if(s == "") {
			//return true;
			ret.push_back(ws);
		}
		
		string stmp(ws);
		char ch = s[0];
		vector<string> & vs = m[ch];
		for(int i = 0; i < vs.size(); ++i) {
			int len = vs[i].size();
			if(s.substr(0, len) == vs[i]) {
				string tmp = s.substr(len);
				if(stmp.size() == 0) {
					ws += vs[i];
				} else {
					ws += string(" ") + vs[i];
				}
				dfs(tmp, m, ws);
				swap(stmp, ws);
			}
		}
	}
private:
	vector<string> ret;
};