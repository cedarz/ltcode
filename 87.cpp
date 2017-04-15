#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isScramble_(string s1, string s2) {
        if(s1 == s2) return true;
		
		int len = s1.size();
        if(len == 1 && s1 != s2) return false;
        
		int part = (len % 2 == 1) ? (len - 1) / 2 : len / 2;
            //cout << part << endl;
            //system("pause");
        string t1 = s1.substr(0, part), t2 = s2.substr(0, part);
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
		bool left = false, right = false;
		if(t1 == t2) {
			left = isScramble(s1.substr(0, part), s2.substr(0, part));
			right = isScramble(s1.substr(part, len - part), s2.substr(part, len - part));
		} else {
			left = isScramble(s1.substr(0, len - part), s2.substr(part, len - part));
			right = isScramble(s1.substr(len - part, part), s2.substr(0, part));
		}
		return left && right;
		/*
		if(s1.substr(0, part) == s2.substr(0, part)) {
            cout << s1 << " " << s2 << " " << (s1 == s2) << endl;
            cout << s1.substr(0, part) << " " << s2.substr(0, part) << endl;
			return isScramble(s1.substr(part, len - part), s2.substr(part, len - part));
		} else if(s1.substr(part, len - part) == s2.substr(part, len - part)) {
			return isScramble(s1.substr(0, part), s2.substr(0, part));
		} else {
			bool left = isScramble(s1.substr(0, part), s2.substr(len - part, part));
			bool right = isScramble(s1.substr(part, len - part), s2.substr(0, len - part));
			return left && right;
		}
		*/

    }
	bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
		
		int len = s1.size();
        if(len == 1 && s1 != s2) return false;
		string t1(s1), t2(s2);
		sort(t1.begin(), t1.end());
		sort(t2.begin(), t2.end());
		if(t1 != t2) return false;
		
        
		for(int part = 1; part < len; ++ part) {
			//通过短路来剪枝
			if(isScramble(s1.substr(0, part), s2.substr(0, part)) && isScramble(s1.substr(part, len - part), s2.substr(part, len - part))) return true;

			if(isScramble(s1.substr(0, len - part), s2.substr(part, len - part)) && isScramble(s1.substr(len - part, part), s2.substr(0, part))) return true;

		}
		return false;
	}
};

int main() {
    std::string s1("rgtae");
    std::string s2("great");
    
    cout << "res : " << Solution().isScramble(s1, s2) << endl;
    
    return 0;
}
