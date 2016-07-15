#include <iostream>
#include <string>

using namespace std;

int next[1024];

void dp(string a) {
    int len = a.size();
    next[0] = 0;
    int k = 0;
    for(int i = 1; i < len; ++i) {
        while(k > 0 && a[i] != a[k]) {
            //cout << i << " " << k << endl;
            k = next[k] - 1;
            //cin.get();
        }
        if(a[i] == a[k]) {
            k++;
        }
        next[i] = k;
    }
    for(int i = 0; i < len; ++i) {
        cout << next[i] << " ";
    }
    cout << endl;
}

int kmp(string s, string p) {
    dp(p);
    int len = s.size();
    int lp = p.size();
    int j = -1;
    for(int i = 0; i < len; ++i) {
        while(j >= 0 && s[i] != p[j + 1]) {
            j = next[j] - 1;
            //cout << " : " << j << endl;
        }
        if(s[i] == p[j + 1]) {
            ++j;
        }
        if(j == p.size() - 1) {
            return i - lp + 1;
        }
        cout << "j : " << j << endl;
    }
    return -1;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
};

int main() {
    string p("issip");
    string s("mississippi");
    //dp(s);
    Solution sol;
    cout << sol.strStr("babba", "bbb") << endl;
    cout << sol.strStr(s, p) << endl;
    cout << sol.strStr("xyabababcdba", "abababcd") << endl;
    cout << sol.strStr("bbaa", "aab") << endl;
    return 0;
}

