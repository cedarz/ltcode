class Solution {
public:
    string reverseVowels(string s) {
        for(int i = 0, j = s.size() - 1; i < j;) {
			while(i < j && !isVow(s[i])) ++i;
			while(i < j && !isVow(s[j])) --j;
			if(i < j) {
				swap(s[i], s[j]);
				++i, --j;
			}
		}
		return s;
    }
	
	bool isVow(int ch) {
		return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
					ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
	}
};