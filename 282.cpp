class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
		
		dfs(ret, num, string(""), 0, 0, 0, target);
		
		return ret;
		
    }
	
	void dfs(vector<string> & ret, string & num, string path, 
		int pos, long long acc, int prev, long long target) {
		
		if(pos == num.size() && acc == target) {
			ret.push_back(path);
			return;
		}
		
		if(pos >= num.size()) return;
		
		for(int i = pos; i < num.size(); ++i) {
		    string sub = num.substr(pos, i - pos + 1);
		    if(sub[0] == '0' && sub.size() > 1) continue;
			long long tmp = stol(sub);
			//cout << sub << " " << tmp << endl;
			if(pos == 0) {
				dfs(ret, num, sub, i + 1, tmp, tmp, target);
			} else {
				dfs(ret, num, path + '+' + sub, i + 1, acc + tmp, tmp, target);
				dfs(ret, num, path + '-' + sub, i + 1, acc - tmp, tmp, target);
				dfs(ret, num, path + '*' + sub, i + 1, acc - prev + prev * tmp, prev * tmp, target);
			}
		}
	}
};