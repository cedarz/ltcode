#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int res = strs[0].size();
        int sz = strs.size();
        for(int i = 1; i < sz; ++i) {
            int p = 0;
            for(p = 0; p < res; ++p) {
                if(strs[0][p] != strs[i][p]) break;
            }
            res = p;
        }
        return string(strs[0], 0, res);
    }
};


