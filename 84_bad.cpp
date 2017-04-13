class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int num = heights.size();
        
        int res = 0;
        for(int i = 0; i < num; ++i) {
            int low = i - 1, high = i + 1;
            int tmp = heights[i];
            int one = heights[i];
            while(low >= 0 && heights[low--] >= heights[i]) {
                tmp += one;
            }
            while(high < num && heights[high++] >= heights[i]) {
                tmp += one;
            }
            res = tmp > res ? tmp : res;
        }
        return res;        
    }
};


