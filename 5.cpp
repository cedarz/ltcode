//Longest Palindromic Substring
//Longest Palindromic Substring
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1001][1001];
void solve(string & s, int & low, int &high) {
    int len = s.size();
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < len; ++i) {
        dp[i][i] = 1;
        if(s[i] == s[i + 1]) dp[i][i + 1] = 1;
    }
    for(int stp = 2; stp < len; ++stp) {
        for(int i = 0; i < len && i + stp < len; ++i) {
            if(s[i] == s[i + stp] && dp[i + 1][i + stp - 1]) {
                dp[i][i + stp] = 1;
            }
        }
    }
    int res = 1;
    low = 0, high = 0;
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < len; ++j) {
            if(dp[i][j] && res < j - i + 1) {
                res = j - i + 1;
                low = i;
                high = j;
            }
        }
    }
}
class Solution {
public:
    
    string longestPalindrome(string s) {
        int low, high;
        solve(s, low, high);
        return string(s.begin() + low, s.begin() + high + 1);
    }
};

int main() {
    cout << Solution().longestPalindrome(string("abaee")) << endl;;
    
    return 0;
}
