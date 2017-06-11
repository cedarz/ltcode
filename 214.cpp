#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
		int last = 0;
        for(int i = 1; i <= s.size(); ++i) {
			int left = i / 2 - 1;
			int right = (i + 1) / 2;
			//cout << left << " " << right << endl;
			while(left >= 0 && right < s.size()) {
				if(s[left] == s[right]) {
					--left;
					++right;
				} else {
					break;
				}
			}
			
			if(left == -1) {
				last = right;
			}
		}
		
		//cout << last << endl;
		string tmp = s.substr(last);
		reverse(tmp.begin(), tmp.end());
		
		return tmp + s;
    }
};

int main() {
	string s("aacecaaa");
	
	cout << Solution().shortestPalindrome(s) << endl;
	cout << Solution().shortestPalindrome("abcd") << endl;
	
	return 0;
}
