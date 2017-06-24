class Solution {
public:
    bool isAnagram(string s, string t) {
		map<char, int> ns, nt;
        for(int i = 0; i < s.size(); ++i) {
			if(ns[s[i]]) ++ns[s[i]];
			else ns[s[i]] = 1;
		}
		for(int i = 0; i < t.size(); ++i) {
			if(nt[t[i]]) ++nt[t[i]];
			else nt[t[i]] = 1;
		}
		
		if(ns.size() != nt.size()) return false;
		for(auto it : ns) {
			if(it.second != nt[it.first]) return false;
		}
		return true;
    }
};