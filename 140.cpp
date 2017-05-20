class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char, vector<string>> m;
		for(int i = 0; i < wordDict.size(); ++i) {
			m[wordDict[i][0]].push_back(wordDict[i]);
		}
		
		vector<bool> vb(s.size(), false);
		is_breakable(s, vb, wordDict);
		cout << vb[0] << endl;
		string ws("");
		if(vb[0]) dfs(s, m, ws, vb, 0);
		return ret;
    }
	
	void dfs(string & s, unordered_map<char, vector<string>> & m, string & ws, 
						vector<bool> & vb, int k) {
		cout <<"# " << k << endl;
		if(k == s.size()) {
			//return true;
			ret.push_back(ws);
		}
		
		string stmp(ws);
		char ch = s[k];
		vector<string> & vs = m[ch];
		for(int i = 0; i < vs.size(); ++i) {
			int len = vs[i].size();
			if(s.substr(k, len) == vs[i]) {
				//string tmp = s.substr(len);
				int kk = k + len;
				if(stmp.size() == 0) {
					ws += vs[i];
				} else {
					ws += string(" ") + vs[i];
				}
				if(vb[kk]) dfs(s, m, ws, vb, kk);
				ws = stmp;
			}
		}
	}
	
	void is_breakable(string & s, vector<bool> & vb, vector<string>& wordDict) {
		int Len = s.size();
		vector<bool> tmp(Len + 1, false);
		tmp[Len] = true;
		for(int i = Len - 1; i >= 0; --i) {
			for(int j = i + 1; j <= Len; ++j) {
				if(tmp[j]) {
					string ts = s.substr(i, j - i);
					if(find(wordDict.begin(), wordDict.end(), ts) != wordDict.end()) {
						tmp[i] = true;
						break;
					}
				}
			}
		}
		copy(tmp.begin(), tmp.end(), vb.begin());
	}
private:
	vector<string> ret;
};