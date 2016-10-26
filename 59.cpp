class Solution {
public:
    static int step[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(0, n));
        vector<vector<int>> visit(n, vector<int>(0, n));
        int dir = 0;
        int stx = 0, sty = 0;
        int cnt = 0;
        while(cnt <= n * n) {
            if(!visit[stx][sty]) {
                mat[stx][sty] = ++cnt;
                visit[stx][sty] = 1;
            }
            int x = stx + Solution.step[dir][0];
            int y = sty + Solution.step[dir][1];
            if(x >= n || x < 0 || y >= n || y < 0 || visit[x][y]) {
                dir = (dir + 1) % 4; 
            }
            stx += Solution.step[dir][0];
            sty += Solution.step[dir][1];
        }
        return mat;
    }
};

