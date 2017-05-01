class Solution {
public:
    bool isPalindrome(string s) {
		size_t sz = s.size();
		size_t cnt = 0;
        for(size_t i = 0; i < sz; ++i) {
			char ch = s[i];
			if(ch <= '9' && ch >= '0') s[cnt++] = ch;
			if((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A')) {
				s[cnt++] = ch <= 'z' && ch >= 'a' ? ch : 'a' + ch - 'A';
			}
		}
		string ss = s.substr(0, cnt);
		return dfs(ss);
    }
	
	bool dfs(string & s) {
		int left = 0;
		int right = s.size() - 1;
		while(left < right && s[left] == s[right]) {
		    ++left;
		    --right;
		}
		return !(left < right);
	}
};