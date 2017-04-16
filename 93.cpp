class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
		for(int i = 0; i < 1 << (len - 1); ++i) {
			vector<int> dot;
			
			int tmp = i;
			
			int loc = 1;
			while(tmp) {
				if(tmp % 2 == 1) {
					dot.push_back(loc);
				}
				tmp /= 2;
				++loc;
			}
			if(dot.size() != 3) continue;
			else dfs(s, dot);
		}
		
		return ips;
    }

private:
	vector<string> ips;
	
	void dfs(string & s, vector<int> & dot) {
	    if(dot[0] > 3 || dot[1] - dot[0] > 3 || dot[2] - dot[1] > 3 || s.size() - dot[2] > 3) return;
		
		string s1 = s.substr(0, dot[0]);
		string s2 = s.substr(dot[0], dot[1] - dot[0]);
		string s3 = s.substr(dot[1], dot[2] - dot[1]);
		string s4 = s.substr(dot[2]);
		
		//cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
		if(atoi_s(s1) && t2 = atoi_s(s2) && t3 = atoi_s(s3) && t4 = atoi_s(s4)) {
			stringstream ss;
			ss << s1 << "." << s2 << "." << s3 << "." << s4;
			ips.push_back(ss.str());
		}
	}
	
	bool atoi_s(string & s) {
		int res = 0;
		int sz = s.size();
		
		if(sz >= 2 && s[0] == '0') return false;
		for(int i = 0; i < sz; ++i) {
			res = res * 10 + (s[i] - '0');
		}
		if(res > 255) return false;
		
		return true;
		
	}
};