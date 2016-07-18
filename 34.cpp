class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        int len = nums.size();
        int left = lbs(nums, 0, len - 1, target);
        if(left == -1) {
            return res;
        } else {
            res[0] = left;
            res[1] = rbs(nums, 0, len - 1, target);
            return res;
        } 
    }
    
    int lbs(vector<int> & nums, int i, int j, int target) {
        int mid = (i + j) / 2;
        while(i < j) {
            if(target <= nums[mid]) {
                j = mid;
            } else{
                i = mid + 1;
            } 
            mid = (i + j) / 2;
        }
        if(nums[i] == target) {
            return i;
        } else {
            return -1;
        }
    }
    
    int rbs(vector<int> & nums, int i, int j, int target) {
        int mid = (i + j + 1) / 2;  // ref: low_bound, up_bound
        while(i < j) {
            if(target >= nums[mid]) {
                i = mid;
            } else {
                j = mid - 1;
            } 
            mid = (i + j + 1) / 2;

        }
        if(nums[i] == target) {
            return i;
        } else {
            return -1;
        }
    }
};


