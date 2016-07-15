class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int unique = nums[0];
        int len = nums.size();
        int cnt = 0;
        for(int i = 1; i < len; ) {
            nums[cnt++] = unique;
            while(i < len && nums[i] == unique) ++i;
            if(i != len) unique = nums[i];
        }
        for(int i = cnt; i < len; ++i) {
            nums.pop_back();
        }
        return cnt;
    }
};

