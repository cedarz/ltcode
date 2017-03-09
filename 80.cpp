class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        
        if(nums.empyt()) return 0;
        
        int ref = nums[0];
        int k = 0;
        int cnt = 0;
        while(k < len) {
            int beg = k;
            while(k < len && nums[k] == ref) ++k;
            nums[cnt++] = ref;
            if(k - beg >= 2) {
                nums[cnt++] = ref;
            }
            ref = nums[k];
        }
        return cnt;
    }
};

