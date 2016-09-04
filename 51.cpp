class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        v.clear();
        N = n;
        memset(cnt, 0, sizeof(cnt));
        vector<string> sol(n, string(n, '.'));
        dfs(sol, 0);
        return v;
    }
    
private:
    vector<vector<string>> v;
    int N;
    int cnt[1024];
    
    void dfs(vector<string> & sol, int ln) {
        if(ln == N) {
            v.push_back(sol);
        }
        for(int i = 0; i < N; ++i) {
            bool is_valid = true;
            if(cnt[i] != 0) {
                is_valid = false;
            }
            for(int j = 1; i - j >= 0 && ln - j >= 0; ++j) {
                if(sol[ln -j][i - j] == 'Q') {
                    is_valid = false;
                    break;
                }
            }
            for(int j = 1; i + j < N && ln - j >= 0; ++j) {
                if(sol[ln - j][i + j] == 'Q') {
                    is_valid = false;
                    break;
                }
            }
            if(is_valid) {
                sol[ln][i] = 'Q';
                cnt[i]++;
                dfs(sol, ln + 1);
                sol[ln][i] = '.';
                cnt[i]--;
            } else {
                continue;
            }
        }
    }
};

