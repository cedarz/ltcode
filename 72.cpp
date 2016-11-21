int dp[1001][1001];

class Solution {
public:
    int minDistance_wrong_solution(string word1, string word2) {
        memset(dp, 0, sizeof(dp));
        int sz1 = word1.size(), sz2 = word2.size();
        
        for(int i = 0; i <= sz1; ++i) {
            dp[i][0] = 0;
        }
        for(int j = 0; j <= sz2; ++j) {
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= sz1; ++i) {
            for(int j = 1; j <= sz2; ++j) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << sz1 << " " << sz2 << " " << dp[sz1][sz2] << endl;
        
        int xe = sz1, ye = sz2, lcs = dp[sz1][sz2];
        int xs = 0, ys = 0;
        int x = sz1, y = sz2;
        while(lcs) {
            if(word1[x - 1] == word2[y - 1]) {
                if(lcs == dp[sz1][sz2]) {
                    xe = x, ye = y;
                }
                if(lcs == 1) {
                    xs = x, ys = y;
                }
                --lcs;
                --x, --y;
            } else {
                if(lcs == dp[x - 1][y]) {
                    --x;
                } else {
                    --y;
                }
            }
        }
        
        int res = max(xs, ys) - 1 + max(sz1 - xe, sz2 - ye) + max(xe - xs, ye - ys) + 1 - dp[sz1][sz2];
               
        
        return res;
        
    }
    
    int minDistance(string word1, string word2) {
        memset(dp, 0, sizeof(dp));
        int sz1 = word1.size(), sz2 = word2.size();
        
        for(int i = 0; i <= sz1; ++i) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= sz2; ++j) {
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= sz1; ++i) {
            for(int j = 1; j <= sz2; ++j) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        
        return dp[sz1][sz2];
    }
    
};



