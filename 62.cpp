int a[101][101];

class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= m; ++i) {
            a[i][1] = 1;
        }
        for(int i = 1; i <= n; ++i) {
            a[1][i] = 1;
            
        }
        for(int i = 2; i <= m; ++i) {
            for(int j = 2; j <= n; ++j) {
                a[i][j] = a[i][j - 1] + a[i - 1][j];
            }
        }
        return a[m][n];
    }
};


