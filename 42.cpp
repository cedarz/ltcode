class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int res = 0;
        int low = 0, hig = 0;
        if(len <= 2) return 0;
        while(height[low] == 0) ++low;
        while(true) {
            hig = low + 1;
            int highest = INT_MIN;
            int __x = hig;
            while(true) {
                if(hig >= len) break;
                // find the one bigger than the left bound if any
                if(height[hig] > height[low]) {
                    __x = hig;
                    break;
                } else {
                    // if none is bigger than the left, find the biggest
                    // as left as it can be, that is why >= exists
                    if(height[hig] >= highest) {
                        __x = hig;
                        highest = height[hig];
                    }
                    ++hig;
                }
            }
            //cout << highest << endl;
            res += min(height[low], height[__x]) * (__x - low - 1);
            for(int i = low + 1; i < __x; ++i) {
                res -= height[i];
            }
            low = __x;
            if(low == len - 1) break;
        }
        return res;
    }
};

