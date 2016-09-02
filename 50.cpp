class Solution {
public:
    double myPow(double x, int n) {
        return n >= 0 ? pow(x, n) : 1 / pow(x, -n);
    }
    
    double pow(double x, int n) {
        double res = 1.0;
        double tmp = x;
        while(n) {
            if(n & 1) {
                res *= tmp;
            }
            tmp *= tmp;
            n >>= 1;
        }
        return res;
    }
};

