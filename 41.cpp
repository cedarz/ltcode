class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            //int cur_i = i;
            int tmp = nums[i];
            while(nums[tmp - 1] != tmp && tmp <= len && tmp >= 1) {
                swap(tmp, nums[tmp - 1]);
                //cur_i = tmp - 1;
            }
        }
        for(int i = 0; i < len; ++i) {
            if(nums[i] != i + 1) return i + 1;
        }
        return len + 1;
    }
};

