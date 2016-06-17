//Median of the Two Sorted Arrays
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int s1 = v1.size();
        int s2 = v2.size();
        int tmp = s1 + s2;
        if(tmp & 1) {
            return find_kth(v1, 0, s1, v2, 0, s2, tmp / 2 + 1);
        } else {
            //return (find_kth(v1, 0, s1, v2, 0, s2, tmp / 2 - 1) + 
                    //find_kth(v1, 0, s1, v2, 0, s2, tmp / 2)) / 2;
            double tp1, tp2;
            tp1 = find_kth(v1, 0, s1, v2, 0, s2, tmp / 2);
            tp2 = find_kth(v1, 0, s1, v2, 0, s2, tmp / 2 + 1);
            return (tp1 + tp2) / 2;
        }
    }
    
    double find_kth(vector<int> & v1, int base1, int s1, vector<int> & v2, int base2,
         int s2, int k) {
        if(s1 > s2) {
            return find_kth(v2, base2, s2, v1, base1, s1, k);
        }
        if(s1 == 0) {
            return v2[base2 + k - 1];
        }
        if(k == 1) {
            return min(v1[base1], v2[base2]);
        }
        int p1 = min(s1, k / 2), p2 = k - p1;
        if(v1[base1 + p1 - 1] <= v2 [base2 + p2 - 1]) {
            return find_kth(v1, base1 + p1, s1 - p1, v2, base2, s2, k - p1);
        } else {
            return find_kth(v1, base1, s1, v2, base2 + p2, s2 - p2, k - p2);
        }
    }   
    
};

int main() {
    int a[] = {1, 2};
    int b[] = {1, 2};
    vector<int> v1(a, a + 2), v2(b, b + 2);
    cout << Solution().findMedianSortedArrays(v1, v2) << endl;;
    return 0;
}
