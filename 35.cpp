class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int len = nums.size();
        return dfs(nums, 0, len - 1, target);
    }
    
    int dfs(vector<int> & nums, int i, int j, int target) {
        int mid = (i + j) / 2;
        while(i <= j) {
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            } 
            mid = (i + j) / 2;
        }
        if(nums[mid] > target) {
            return mid - 1 >= 0 ? mid - 1 : 0;
        } else {
            return mid + 1;
        }
    }
};

