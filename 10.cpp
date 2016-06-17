#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;
void print();

int dp[1024][1024];
class Solution {
public:
    bool solve(string & s, string & p) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1; 
        int ls = s.size(), lp = p.size();
        for(int j = 1; j <= lp; ++j) {
            if(p[j - 1] == '.') {
                //cout << "## " << dp[i - 1][j - 1] << endl;
                //cout << i - 1 << " " << j - 1 << endl;
                dp[0][j] = 0;
            } else if(p[j - 1] == '*') {
                dp[0][j] |= dp[0][j - 2];
            }
        }
        
        for(int i = 1; i <= ls; ++i) {
            for(int j = 1; j <= lp; ++j) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    //cout << "## " << dp[i - 1][j - 1] << endl;
                    //cout << i - 1 << " " << j - 1 << endl;
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[j - 1] == '*') {
                    if(p[j - 2] != '.') {
                        //cout << p[j - 2] << endl;
                        dp[i][j] = dp[i][j - 2]; //j > 2, must have a element before *
                        int k = i - 1;
                        while(s[k] == p[j - 2] && dp[k + 1][j - 2] != 1 && k >= 0 ) --k;
                        //printf("(%d, %d)\n", k + 1, j - 2);
                        dp[i][j] |= dp[k + 1][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 2];
                        int k = i;
                        while(dp[k][j - 2] != 1 && k > 0) --k;
                        dp[i][j] |= dp[k][j - 2];
                    }
                }
            }
        }         
        return dp[ls][lp];
    }
    
    bool isMatch(string s, string p) {
        return solve(s, p);        
    }
};

void print() {
    for(int i = 0; i <= 4; ++i) {
        for(int j = 0; j <= 6; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    Solution s;
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "aa") << endl;
    cout << s.isMatch("aaa","aa") << endl;
    cout << s.isMatch("aaa","a*") << endl;
    cout << s.isMatch("aa", ".*") << endl;
    cout << s.isMatch("ab", ".*") << endl;
    cout << s.isMatch("aab", "c*a*b*") << endl;
    cout << s.isMatch("aaa", "ab*a*c*a") << endl;
    cout << s.isMatch("aa", "ab*a*") << endl;
    cout << s.isMatch("aa", "aa*") << endl;
    cout << s.isMatch("a", ".*..a*") << endl;
    
    return 0;
}
    
