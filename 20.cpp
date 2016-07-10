#include <stack>
#include <string>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        bool res = true;
        stack<char> stk;
        int len = s.size();
        if(len == 0) return true;
        for(int i = 0; i < len; ++i) {
            if(stk.empty()) {
                stk.push(s[i]);
                if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                    return false;
                }
            } else if(stk.top() == '(' && s[i] == ')' 
                        || stk.top() == '{' && s[i] == '}'
                        || stk.top() == '[' && s[i] == ']') {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        res = stk.empty();
        return res;       
    }
};


