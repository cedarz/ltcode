class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if(nums.empty()) return false;
        
        int m = (low + high) / 2;
        while(low <= high) {
            if(target == nums[m]) {
                return true;
            }
            if(nums[low] < nums[m]) {
                if(target >= nums[low] && target < nums[m]) {
                    high = m - 1;
                } else {
                    low = m + 1;
                }
            } else if(nums[low] > nums[m]) {
                if(target > nums[m] && target <= nums[high]) {
                    low = m + 1;
                } else {
                    high = m - 1;
                }
            } else {
                high--;
            }
            m = (low + high) / 2;
        } 
        return false;
    }
};


