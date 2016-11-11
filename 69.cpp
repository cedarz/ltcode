#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int low = 1, high = x;
        int mid = (low + high) / 2;
        while(low <= high) {
            mid = (low + high) / 2;
            double tmp = (double)x / mid;
            //cout << low << ": " << high << " " << tmp << " " << mid << endl;
            if(tmp > mid + 1){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }      

        return x / low >= low ? low : low - 1;
    }
};




int main() {
    Solution s;
    cout << s.mySqrt(8) << endl;
    cout << s.mySqrt(123) << endl;
    cout << s.mySqrt(2147483647) << endl;
    
    return 0;
}

