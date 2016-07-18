class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int r = -1; 
        int len = nums.size();
        
        for(int i = 0; i < len - 1; ++i) {
            if(nums[i] > nums[i + 1]) {
                r = i;
                break;
            }
        }
        
        if(r == -1) {
            return dfs(nums, 0, len - 1, target);
        }
        if(target > nums.back()) {
            return dfs(nums, 0, r, target);
        } else {
            return dfs(nums, r + 1, len - 1, target);
        }
    }
    
    int dfs(vector<int> & nums, int i, int j, int target) {
        int res = -1;
        int mid = (i + j) / 2;
        while(i < j) {
            if(target == nums[mid]) {
                return mid;
            } else if(target > nums[mid]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
            mid = (i + j) / 2;
        }
        return -1;
    }
};

