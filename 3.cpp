#include <string>
#include <iostream>
#include <cstring>
using namespace std;

unsigned char mp[256];
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t i, j;
        int res = 1, tmp = 1;
        memset(mp, 0, sizeof(mp));
        if(s.empty()) return 0;
        mp[s[0]] = 1;
        for(i = 0, j = 1; j < s.size(); ) {
            if(mp[s[j]] == 0) {
                ++tmp;
                mp[s[j]] = 1;
                ++j; 
            } else {
                res = (res < tmp) ? tmp : res;
                while(s[i] != s[j]) {
                    --tmp;
                    mp[s[i]] = 0;
                    ++i;
                }
                ++i;++j;
            }
            if(j == s.size()) {
                res = (res < tmp) ? tmp : res;
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin>>s;
    Solution obj;
    
    cout<<obj.lengthOfLongestSubstring(string(""))<<endl;
    cout<<obj.lengthOfLongestSubstring(s)<<endl;
    return 0;
}
