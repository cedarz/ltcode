//Reverse Integer
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool pos = (x >= 0);
        if(!pos) x = -x;
        int res = 0;
        long long over = 0;
        while(x) {
            over = over * 10 + x % 10;
            res = over;
            x /= 10;
        }
        if(over != res) return 0;
        if(!pos) res = -res;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.reverse(-123000) << endl;
    cout << s.reverse(1534236469) << endl;
    cout << (-1u >> 1) << endl;
    return 0;
}

