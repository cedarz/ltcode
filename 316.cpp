#include <unordered_map>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cmi;
		for(auto ch : s) {
			++cmi[ch];
		}
		
		string res("");
		int i = 0;
		stack<int> stk;
		
		char tmp = s[0];
		int loc = 0;
		for(int i = 0; i < s.size(); ) {
            cout << i << endl;
			if(cmi[s[i]] == 1) {
				if(s[i] < tmp) {
					loc = i;
					tmp = s[i];
				}
                --cmi[s[i]];
				
				stk.push(i);
                cout << i << " -> " << s[i] << " " << cmi[s[i]] << endl;
				res += string(1, tmp);
				
								
				while(!stk.empty()) {
					int t = stk.top();
					cout << "stk : " << t << endl;
                    stk.pop();
					if(t == loc) break;
					else {
						++cmi[s[t]];
						//cout << t << " " << s[t] << " " << cmi[s[t]] << endl;
					}
				}
				cmi[tmp] = 0;
				i = loc + 1;
				while(i < s.size() && cmi[s[i]] == 0) ++i;
				if(i < s.size()) {
					tmp = s[i];
					loc = i;
				} else break;
			} else if(cmi[s[i]] == 0) {
				++i;
			} else if(cmi[s[i]] > 1) {
				--cmi[s[i]];
				stk.push(i);

				if(s[i] < tmp) {
					loc = i;
					tmp = s[i];
				}
				++i;
			}
		}
		return res;
	}
};

int main() {
	Solution sol;
	cout << sol.removeDuplicateLetters("bddbccd") << endl;
	return 0;
}
