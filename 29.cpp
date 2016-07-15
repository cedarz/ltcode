#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;
        if(a == 0 && b != 0) return 0;
        int sig = !((a > 0) ^ (b > 0));
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long long res = 0;
        while(a >= b) {
            long long tmp = 1;
            long __b = b;
            while((__b << 1) <= a) {
                __b <<= 1;
                tmp <<= 1;
            }
            a -= __b;
            res += tmp;
        }
        res = sig ? res : -res;
        cout << sig << " " <<  res << endl;
        if(res >= INT_MAX) res = INT_MAX;
        return res;
    }
};

int main() {
    Solution s;
    //cout << s.divide(2, 2) << endl;
    cout << s.divide(-2147483648, -1) << endl;    
    return 0;
}
