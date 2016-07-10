#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dig[8][5] = {
    {3, 'a', 'b', 'c'},
    {3, 'd', 'e', 'f'},
    {3, 'g', 'h', 'i'},
    {3, 'j', 'k', 'l'},
    {3, 'm', 'n', 'o'},
    {4, 'p', 'q', 'r', 's'},
    {3, 't', 'u', 'v'},
    {4, 'w', 'x', 'y', 'z'}
};
    
vector<string> res;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.empty()) return res;
        string str(digits);
        dp(digits, 0, str);
        return res;
        
    }
    
    void dp(string & digits, int p, string str) {
        if(p == digits.size()) {
            res.push_back(str); 
        } else {
            for(int i = 1; i <= dig[digits[p] - '0' - 2][0]; ++i) {
                str[p] = dig[digits[p] - '0' - 2][i];
                dp(digits, p + 1, str);
            }
        }
    }
    
};

int main() {
    Solution s;
    s.letterCombinations("23");
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    
    return 0;
}
