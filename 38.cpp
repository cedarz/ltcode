#include <string>
#include <iostream>
#include <sstream>

using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        string res;
        for(int i = 2; i <= n; ++i) {
            res.clear();
            std::stringstream ss;
            char ch = s[0];
            int cnt = 1;
            int len = s.size();
            for(int x = 1; x <= len; ++x) {
                char cur = (x == len) ? '.' : s[x];
                if(cur == s[x - 1]) {
                    ++cnt;
                } else {
                    //cout << cnt << " " << ch << endl;
                    ss << cnt << ch;
                    res += ss.str();
                    ss.str("");
                    cnt = 1; 
                    ch = s[x];
                }
            }
            s = res;
        }
        return s;        
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(100) << endl;;
    
    return 0;
}
