#include <vector>
#include <string>
#include <iostream>

using namespace std;

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        string simplifyPath(string path) {
            v.clear();
            v.push_back("/");
            int sz = path.size();
            int be = 1, en= 0;
            int dir = 0;
            if(path[sz - 1] != '/') {
                path.push_back('/');
                ++sz;
            }
            for(int i = 1; i < sz; ++i) {
                if(path[i] == '/') {
                    string tmp = path.substr(be, i - be);
                    //cout << tmp << endl;
                    if(tmp == string(i - be, '.') && i - be <= 2) {
                        //cout << i - be << endl;
                        for(int pb = 0; pb < i - be - 1; ++pb) {
                            if(v.size() > 1) v.pop_back();
                        }
                    } else {
                        v.push_back(tmp);
                    }
                    be = i + 1;
                }
            }
            if(v.size() == 1) {
                return v[0];
            } else {
                string res = "";
                for(int i = 1; i < v.size(); ++i) {
                    res += "/" + v[i];
                }
                return res;
            }

        }

        void print() {
            for(int i = 0; i < v.size(); ++i) {
                cout << v[i] << endl;
            }
        }
    private:
        vector<string> v;

};

int main() {
    Solution s;
    cout << s.simplifyPath("/a/./b/../../c/") << endl;;
    cout << s.simplifyPath("/b") << endl;;
    cout << s.simplifyPath("/./b/../c/") << endl;;
    //s.print();
    return 0;
}

