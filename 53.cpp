class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp = 0;
        int res = INT_MIN;
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            tmp += nums[i];
            res = max(res, tmp);
            if(tmp < 0){
                tmp = 0;
            }
        }
        return res;
    }
};

