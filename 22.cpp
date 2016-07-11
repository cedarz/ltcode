#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> res;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        if(n <= 0) return res;
        string s(n * 2, ' ');
        dp(s, 0, n, n);
        return res;
    }
    
    void dp(string s, int loc, int lp, int rp) {
        if(lp == 0 && rp == 0) {
            res.push_back(s);
        }
            
        if(lp == rp) {
            s[loc] = '(';
            dp(s, loc + 1, lp - 1, rp);
        } else if(lp > 0) {
            s[loc] = '(';
            dp(s, loc + 1, lp - 1, rp);
            s[loc] = ')';
            dp(s, loc + 1, lp, rp - 1);
        } else if(lp == 0) {
            for(int i = 0; i < lp + rp; ++i) {
                s[loc + i] = ')';
            }
            dp(s, loc + lp + rp, 0, 0);
        }
    }
};

