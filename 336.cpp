class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> ht;
		vector<vector<int>> res;
		for(int i = 0; i < words.size(); ++i) {
			string tmp(words[i]);
			reverse(tmp.begin(), tmp.end());
			ht[tmp] = i;
		}
		
		for(int w = 0; w < words.size(); ++w){
			string & word = words[w];
			for(int i = 0; i <= word.size(); ++i) {
				string left = word.substr(0, i);
				string right = word.substr(i);
				//cout << left << " " << right << endl;
				if(ht.find(left) != ht.end() && isPalin(right) && w != ht[left]) {
					vector<int> tmp({w, ht[left]});
					res.push_back(tmp);
				}
				if(ht.find(right) != ht.end() && isPalin(left) && ht[right] != w) {
					vector<int> tmp({ht[right], w});
					res.push_back(tmp);
				}
			}
		}
		return res;
    }
	
	bool isPalin(string & s) {
		//bool flag = true;
		int i = 0, j = s.size() - 1;
		while(i < j) {
			if(s[i] != s[j]) {
				return false;
			}
			++i, --j;
		}
		return true;
	}
};