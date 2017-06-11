class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ls = s.size(), lt = t.size();
		if(ls != lt) return false;
		
		unordered_map<char, char> m;
		vector<char> chs;
		for(int i = 0; i < ls; ++i) {
			if(m.find(s[i]) == m.end()) {
				//chs.push_back(s[i]);
				for(auto it = m.begin(); it != m.end(); ++it) {
					if(it->second == t[i]) return false;
				}
				m[s[i]] = t[i];
			} else {
				if(m[s[i]] != t[i]) return false;
			}
		}
		//sort(chs.begin(), chs.end());
		//cout << chs.size() << endl;
		//for(int i = 0; i < chs.size(); ++i) {
			//cout << chs[i] << " " << m[chs[i]] << endl;
		//}
		//for(int i = 1; i < chs.size(); ++i) {
		//	if(m[chs[i]] <= m[chs[i - 1]]) return false;
		//}
		
		return true;
    }
};