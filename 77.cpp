#include <vector>
#include <iostream>

using namespace std;
vector<vector<int> > res;  
    
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        res.clear();
        vector<int> v;
        dfs(v, 1, n, k);
        return res;
    }
    
    void dfs(vector<int> v, int low, int high, int k) {
        if(k == 0) {
            res.push_back(v);
            cout << v[0] << " " << v[1] << endl;
            return;
        }
        for(int i = low; i <= high - k + 1; ++i) {
            vector<int> tmp(v);
            tmp.push_back(i);
            dfs(tmp, i + 1, high, k - 1);
        }
    }
private:

};

int main() {
    Solution s;
    s.combine(4,2);
    
    return 0;
}
