#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        if(num >= 1000) {
            return string(num / 1000, 'M') + intToRoman(num % 1000);
        } else if(num >= 100) {
            if(num >= 900) {
                return string("CM") + intToRoman(num - 900);
            } else if(num >= 500) {
                return string("D") + string((num - 500) / 100, 'C') + intToRoman(num % 100);
            } else if(num >= 400) {
                return string("CD") + intToRoman(num - 400);
            } else {
                return string(num / 100, 'C') + intToRoman(num % 100);
            }
        } else if(num >= 10) {
            if(num >= 90) {
                return string("XC") + intToRoman(num - 90);
            } else if(num >= 50) {
                return string("L") + string((num - 50) / 10, 'X') + intToRoman(num % 10);
            } else if(num >= 40) {
                return string("XL") + intToRoman(num - 40);
            } else {
                return string(num / 10, 'X') + intToRoman(num % 10);
            }
        } else if(num >= 1) {
            if(num >= 9) {
                return string("IX");
            } else if(num >= 5) {
                return string("V") + string(num - 5, 'I');
            } else if(num >= 4) {
                return string("IV");
            } else {
                return string(num , 'I');
            }
        } else {
            return string();
        }
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(3000) << endl;;
    cout << s.intToRoman(1880) << endl;
    cout << s.intToRoman(3333) << endl;
}
