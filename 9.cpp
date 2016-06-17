//Palindrome Number
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long long tmp = x;
        if(tmp < 0) return false;
        long long rev = 0;
        while(x) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        //cout << tmp << " " << rev << endl;
        if(rev == tmp) return true;
        else return false;
    }
};


int main() {
    Solution s;
    cout << s.isPalindrome(23432) << endl;
    
    return 0;
}
