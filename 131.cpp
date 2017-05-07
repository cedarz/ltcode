class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return res;
		
		vector<string> path;
		dfs(s, path);
		
		return res;		
    }
	
	bool is_palindrome(string & s) {
		int low = 0, high = s.size() - 1;
		while(low <= high && s[low] == s[high]) {
			++low;
			--high;
		}
		if(low <= high) return false;
		else return true;
	}
	void dfs(const string & s, vector<string> & path) {
		if(s.empty()) res.push_back(path);
		int sz = s.size();
		for(int i = sz; i >= 1; --i) {
			string ss = s.substr(0, i);
			if(is_palindrome(ss)) {
				path.push_back(ss);
				dfs(s.substr(i), path);
				path.pop_back();
			}
		}
	}
private:
	vector<vector<string>> res;
};