class Solution {
public:
	// 数字的数量也要考虑
    string getHint(string secret, string guess) {
        //unordered_map<char, int> scow;
		//unordered_map<char, int> gcow;
		vector<int> scow(10, 0);
		vector<int> gcow(10, 0);
		if(secret.size() != guess.size()) return "0A0B";
		
		int bull = 0, cow = 0;
		for(int i = 0; i < secret.size(); ++i) {
			if(secret[i] == guess[i]) ++bull;
			else {
				++scow[secret[i] - '0'];
				++gcow[guess[i] - '0'];
			}
		}
		for(int i = 0; i < 10; ++i) {
			cow += min(scow[i], gcow[i]);
		}
		stringstream ss;
		ss << bull << "A" << cow << "B";
		return ss.str();
		
    }
};