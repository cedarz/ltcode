class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            int cur_i = i;
            //int tmp = nums[i];
            while(cur_i + 1 != nums[cur_i] && nums[cur_i] <= len && nums[cur_i] >= 1) {
                int tmp = nums[nums[cur_i] - 1];
                nums[nums[cur_i] - 1] = nums[cur_i];
                cur_i = nums[cur_i] - 1;
            }
        }
        for(int i = 0; i < len; ++i) {
            if(nums[i] != i + 1) return i + 1;
        }
        return len + 1;
    }
};

