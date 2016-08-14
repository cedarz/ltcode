class Solution {
public:
    int trap(vector<int>& height) {
        int lowest = INT_MAX;
        int len = height.size();
        bool flag = false;
        int res = 0;
        while(true) {
            flag = false;
            for(int i = 0; i < len; ++i) {
                if(height[i] > 0 && height[i] < lowest) {
                    lowest = height[i];
                }
            }
            int low = 0, hig = 0;
            while(true) {
                while(height[low] == 0) ++low;
                hig = low + 1;
                while(hig < len && height[hig] == 0) ++hig;
                if(hig >= len) break;
                else {
                    res += lowest * (hig - len - 1);
                    low = hig;
                    flag = true;
                }
            }
            if(!flag) break;
            for(int i = 0; i < len; ++i) {
                height[i] = height[i] - lowest <= 0 ? 0: height[i] - lowest;
            }
        }
        return res;
         
    }
};

