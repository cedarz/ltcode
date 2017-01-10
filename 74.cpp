#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.empty()) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int> c;
        
        for(int i = 0; i < row; ++i) {
            c.push_back(matrix[i][0]);
        }
        
        int loc = -1;
        int res = bsearch(c, target, loc);
        if(res != -1) return true;
        c.clear();
        for(int i = 0; i < col; ++i) {
            c.push_back(matrix[loc][i]);
        }
        res = bsearch(c, target, loc);
        if(res != -1) {
            return true;
        } else {
            return false;
        }
        
        
        
        
    }
    
    int bsearch(vector<int> & v, int target, int & loc) {
        int len = v.size();
        int low = 0, high = len - 1;
        int mid = (low + high) / 2;
        int res = -1;
        
        while(low <= high) {
            mid = (low + high) / 2;
            cout << mid << " : " << v[mid] << endl;
            if(v[mid] == target) {
                res = mid;
                break;
            } else if(v[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << "high : " << high << endl;
        loc = high;
        if(loc < 0) ++loc;
        cout << "loc " << loc << endl;
        return res;
    }
};

int main() {
    Solution s;
    int a[] = {1};
    vector<int> v(a, a + 1);
    
    int loc =  -3;
    cout << s.bsearch(v, 0, loc) << endl;
    cout << "loc : " << loc << endl;
    
    return 0;
}
    
