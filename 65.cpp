class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        int index = 0;
        if(s.empty()) return false;
        if(s == ".") return false;
        if(s[index] == '+' || s[index] == '-') {
            ++index;
            if(index == len) return false;
        }
        if(s[index] == '0') ++index;
        else {
            while(s[index] <= '9' && s[index] >= '1') ++index;
        }
        if(index == len) {
            return true;
        } else {
            if(s[index] == '.') {
                ++index;
                while(s[index] <= '9' && s[index] >= '0') ++index;
            }
        }
        if(index == len) {
            return true;
        } else {
            if(s[index] =='e' || s[index] == 'E') ++index;
            else return false;
            if(index == len) return false;
            else {
                if(s[index] == '-' || s[index] == '+') ++index;
                if(index == len) return false;
                else {
                    while(s[index] <= '9' && s[index] >= '0') ++index;
                    if(index != len) return false;
                }
            }
        }
                
        return true;
    }
};

