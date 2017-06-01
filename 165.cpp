class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
		split(version1, v1);
		split(version2, v2);
		for(int i = 0; i < v1.size(); ++i) {
		    //cout << v1[i] << v2[i] << endl;
			if(v1[i] < v2[i]) {
				return -1;
			} else if(v1[i] > v2[i]) {
				return 1;
			}
		}
		return 0;
    }
	
	void split(string & s, vector<int> & v) {
		int st = 0;
		//s.push_back('.');
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '.') {
				v.push_back(str2int(s.substr(st, i - st)));
				st = i + 1;
			}
			if(i == s.size() - 1) {
				v.push_back(str2int(s.substr(st)));
				//st = i + 1;
			}
		}
	}
	int str2int(const string & s) {
		int ret = 0;
		for(int i = 0; i < s.size(); ++i) {
			ret = ret * 10 + s[i] - '0';
		}
		return ret;
	}
};