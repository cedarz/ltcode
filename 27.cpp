class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int len = nums.size();
        int cnt = 0;
        for(int i = 0; i != len; ++i) {
            if(nums[i] != val) nums[cnt++] = nums[i];
        }
        for(int i = cnt; i != len; ++i) {
            nums.pop_back();
        }
        return cnt;
    }
};

