class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length() - 1;
        int res = 0;
        while(len >= 0 && !(s[len] <= 'Z' && s[len] >= 'A' || s[len] <= 'z' && s[len] >= 'a')) {
            --len;
        }
        while(len >=0 && (s[len] <= 'Z' && s[len] >= 'A' || s[len] <= 'z' && s[len] >= 'a')) {
            ++res;
            --len;
        }
        return res;
            
    }
};


