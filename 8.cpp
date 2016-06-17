//String to Integer (atoi)
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        bool pos = true;
        bool overflow = false;
        int res = 0;
        long long over = 0;
        if(s.empty()) return 0;
        while(i < s.size() && s[i] == ' ') ++i;
        if(s[i] == '-') {
            pos = false;
            ++i;
        } else if(s[i] == '+') {
            ++i;
        }
        
        while(i < s.size() && isdigit(s[i])) {
            long long tmp = over * 10 + s[i] - '0';
            if(tmp / 10 != over) {
                overflow = true;
                break;
            }
            over = tmp;
            ++i;
        }
        if(pos) res = over;
        else res = -over;
        if(pos && (res != over || overflow)) return INT_MAX;
        if(!pos && (res != -over || overflow)) return INT_MIN;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("-123hell") << endl;
    cout << s.myAtoi("-+123hell") << endl;
    cout << s.myAtoi("18446744073709551617") << endl;
    
    return 0;
}

