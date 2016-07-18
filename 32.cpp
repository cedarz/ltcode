#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        stack<int> stk;
        int len = s.size();
        int start = 0;
        int res = 0;
        for(int i = 0; i < len; ++i) {
            if(s[i] == '(') {
                stk.push(i);
                if(res < i - start) res = i - start;
            } else {
                if(!stk.empty()) {
                    stk.pop();
                    if(stk.empty()) {
                        if(res < i - start) res = i - start;
                    } else {
                        if(res < i - stk.top() + 1) {
                            res = i - stk.top() + 1;
                            stk.pop();
                        }
                    }
                } else {
                    start = i + 1;
                }
            }
        }
        return res;
                        
            
    }
};



