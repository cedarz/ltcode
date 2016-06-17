//ZigZag Conversion
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nrs) {
        int len = s.size();
        if(nrs == 1 || nrs >= len) return s;
        int stp = (nrs << 1) - 2;
        string t;
        for(int i = 0; i < nrs; ++i) {
            for(int j = i; j < len; j += stp) {
                t.push_back(s[j]);
                //cout << " j " << j << endl;
                int tmp = j + stp - 2 * i;
                if(i && i != nrs - 1 && tmp < len) {
                    //cout << "tmp " <<tmp << endl;
                    t.push_back(s[tmp]);
                }
            }
        }
        return t;
    }
string convert_(string S, int N) {
    if(N < 2 || S.length() <= N)
        return S;
    string V[N];
    int row = 0;
    bool Down;
    for(int i=0;i<S.length();i++)
    {
        V[row].push_back(S[i]);
        if(row == N-1)
            Down = false;
        else if(row == 0)
            Down = true;
        if(Down)
            row++;
        else
            row--;
    }
    string ans = "";
    for(int i=0;i<N;i++)
        ans += V[i];
    return ans;
}
    
};

int main() {
    cout << Solution().convert("PAYPALISHIRING", 3) << endl;
    cout << Solution().convert("AB", 1) << endl;
    cout << Solution().convert("ABCDE", 4) << endl;
    
    return 0;
}
