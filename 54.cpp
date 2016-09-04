#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> v;
        if(matrix.empty()) return v;
        bound[0] = matrix[0].size() - 1;
        bound[1] = matrix.size() - 1;
        bound[2] = bound[3] = 0;
        
        int dir = 0;
        bool has_element = false;
        
        int i = 0, j = 0;
        //v.push_back(matrix[0][0]);
        while(true) {
            has_element = false;
            int first = (dir + 2) % 4;
            switch(dir) {
                case 0: 
                    for(j = bound[first]; j <= bound[dir]; ++j) {
                        v.push_back(matrix[i][j]);
                        cout << " ## " << matrix[i][j] << endl;
                        has_element = true;
                    }
                    ++bound[3];
                    --j;
                    break;
                case 1:
                    cout << bound[3] << " " << bound[dir] << endl;
                    for(i = bound[first]; i <= bound[dir]; ++i) {
                        v.push_back(matrix[i][j]);
                        cout << " ## " << matrix[i][j] << endl;
                        has_element = true;
                    }
                    --i;
                    --bound[0];
                    break;
                case 2:
                    for(j = bound[first]; j >= bound[dir]; --j) {
                        v.push_back(matrix[i][j]);
                        cout << " ## " << matrix[i][j] << endl;
                        has_element = true;
                    }
                    ++j;
                    --bound[1];
                    break;
                case 3:
                    for(i = bound[first]; i >= bound[dir]; --i) {
                        v.push_back(matrix[i][j]);
                        cout << " ## " << matrix[i][j] << endl;
                        has_element = true;
                    }
                    ++i;
                    ++bound[2];
                    break;
            }
            dir = (dir + 1) % 4;
            if(!has_element) break;
        }
        v.push_back(matrix[i][j]);
        return v;
    }
private:
    int bound[4]; // right, down, left, up
};

int a[] = {1, 2, 3};
int b[] = {4, 5, 6};
int c[] = {7, 8, 9};

int main() {
    vector<int> va(a, a + 3);
    vector<int> vb(b, b + 3);
    vector<int> vc(c, c + 3);
    vector<vector<int> > v;
    v.push_back(va);
    v.push_back(vb);
    v.push_back(vc); 

    Solution s;
    vector<int> res = s.spiralOrder(v);

    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}

