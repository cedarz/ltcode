class Solution {
public:
    int _numDecodings(string s) {
        if(s.size() == 1) {
            if(s[0] <= '9' && s[0] > '0') return 1;
            else return 0;
        }
		if(s.empty()) return 0;
		if(s.size() == 2) {
		    int tmp = (s[0] - '0') * 10 + (s[1] - '0');
		    
		    if(tmp == 10 || tmp == 20) return 1;
		    else if(tmp >= 11 && tmp <= 26) return 2;
		}
		
		int tmp = (s[0] - '0') * 10 + (s[1] - '0');
		//if(s[0] == '0') return 0;
		return s[0] == '0' ? 0 : numDecodings(s.substr(1)) + (tmp >= 10 && tmp <= 26 ? numDecodings(s.substr(2)) : 0);
    }
	int numDecodings(string s) {
		return dp(s);
	}
	
	int dp(string & s) {
		int num = s.size();
		vector<int> v(num + 1, 0);
		
		//dp[num] = 0;
		if(s[num - 1] <= '9' && s[num - 1] > '0') {
			v[num - 1] = 1;
		} else {
			v[num - 1] = 0;
		}
		if(s.size() >= 2) {
		    int tmp = (s[num - 2] - '0') * 10 + (s[num - 1] - '0');
		    
		    if(tmp == 10 || tmp == 20) v[num - 2] = 1;
		    else if(tmp >= 11 && tmp <= 26) v[num - 2] = 2;
		    else v[num - 2] = v[num - 1];
		    if(s[num - 2] == '0') v[num - 2] = 0;
		}
		
		for(int i = num - 3; i >= 0; --i) {
		    int tmp = (s[i] - '0') * 10 + (s[i + 1] - '0');
			v[i] = s[i] == '0' ? 0 : v[i + 1] + (tmp >= 10 && tmp <= 26 ? v[i + 2] : 0);
			//cout << v[i] << endl;
		}
		return v[0];
	}
};