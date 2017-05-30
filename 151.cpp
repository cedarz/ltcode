#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    void reverseWords(string &s) {
        vector<string> vs;
		int st = 0, ed = -1;
		int i = 0;
		while(st < s.size()) {
			if(s[st] == ' ') {
				++st;
			} else {
				ed = st;
				while(s[ed] !=  ' ' && st < s.size()) {
					++ed;
				}
				vs.push_back(s.substr(st, ed - st));
				st = ed;
			}
		}
        s = "";
		for(int i = vs.size() - 1; i >= 0; --i) {
            if(i == vs.size() - 1) {
                s += vs[i];
            } else {
                s += string(" ") + vs[i];
            }
		}
    }
};

int main() {
	string s = "the sky is blue";
	Solution().reverseWords(s);
	cout << s << endl;
	
	return 0;
}
