class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mtos;
		unordered_map<string, char> mtoc;
		vector<string> v;
		
		int loc = 0; 
		while(loc < str.size()) {
			while(str[loc] == ' ') ++loc;
			int st = loc, ed = loc;
			while(ed < str.size() && str[loc] != ' ') ++ed;
			v.push_back(str.substr(st, ed - st));
			loc = ed;
		}
		
		if(pattern.size() != v.size()) return false;
		for(int i = 0; i < pattern.size()) {
			if(mtos.find(pattern[i]) != mtos.end()) {
				if(mtos[pattern[i]] != v[i]) return false;
			} else {
				mtos[pattern[i]] = v[i];
			}
			if(mtoc.find(v[i]) != mtoc.end()) {
				if(mtoc[v[i]] != pattern[i]) return false;
			} else {
				mtoc[v[i]] = pattern[i];
			}
		}
		return true;
    }
};