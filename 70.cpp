class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        } else {
            int a1 = 1, a2 = 2;
            int a3 = 0;
            for(int i = 3; i <= n; ++i) {
                a3 = a1 + a2;
                a1 = a2;
                a2 = a3;
            }
            return a3;
        }
        
    }
};

