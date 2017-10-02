class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits(words.size(), 0);
        int cnt = 0;
		for(auto w : words) {
			for(auto ch : w) {
				bits[cnt++] |= 1 << (ch - 'a');
			}
		}
		
		int res = 0;
		for(int i = 0; i < words.size(); ++i) {
			for(int j = i + 1; j < words.size(); ++j) {
				if(bits[i] & bits[j] == 0) {
					res = max(res, words[i].size() * words[j].size());
				}
			}
		}
		return res;
    }
};