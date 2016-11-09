#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size();
        int lb = b.size();
        string res;
        int i = 0, j = 0;
        int carry = 0;
        for(i = la - 1, j = lb - 1; i >= 0 && j >= 0; --i, --j) {
            int s = (a[i] - '0') ^ (b[j] - '0') ^ carry;
            carry1 = (a[i] - '0') & (b[j] - '0');
            if(carry1) carry = 1;
            else carry &= carry1;
            res.push_back('0' + s);
        }
        
        if(i < 0) {
            for(; j >= 0; --j) {
                int s = (b[j] - '0') ^ carry;
                carry = (b[j] - '0') & carry;
                res.push_back(s + '0');
            }
        } else {
            for(; i >= 0; --i) {
                int s = (a[i] - '0') ^ carry;
                carry = (a[i] - '0') & carry;
                res.push_back(s + '0');
            }
        }
        cout << res << endl;
        if(carry) res.push_back(carry + '0');
        return string(res.rbegin(), res.rend());
                
            
        
    }
};

int main() {
    
    Solution s;
    s.addBinary("0", "0");
    return 0;
}

