#include <iostream>
#include <string>

using namespace std;

int a[255];
class Solution {
public:
    static void init() {
        a['I'] = 1;
        a['V'] = 5;
        a['X'] = 10;
        a['L'] = 50;
        a['C'] = 100;
        a['D'] = 500;
        a['M'] = 1000;
    }
    int romanToInt(string s) {
        init();
        int res = 0;
        int len = s.size();
        for(int i = 0; i < len; i++) {
            if(i + 1 < len && a[s[i + 1]] > a[s[i]]) {
                res += a[s[i + 1]] - a[s[i]]; 
                ++i;
            } else {
                res += a[s[i]];
            }
        } 
        return res;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("MCDXXXVII") << endl;
    
    return 0;
}
