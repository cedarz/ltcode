class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
		vector<string> vs;
		if(s.size() < 10) return vs;
		
		for(int i = 0; i < s.size() - 10; ++i) {
			string tmp = s.substr(i, 10);
			if(m.find(tmp) != m.end()) {
				m[tmp]++;
				if(m[tmp] == 2) {
					vs.push_back(tmp);
				}
			} else {
				m[tmp] = 1;
			}
		}
		
		return vs;
    }
};