class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        do{
            v.push_back(nums);
        } while(next_permutation(nums));
        return v;
    }
    
    bool next_permutation(vector<int> & nums) {
        int len = nums.size();
        int k = len - 2;
        while(k >= 0 && nums[k] > nums[k + 1]) --k;
        if(k < 0) return false;
        int least_max = INT_MAX;
        int lmax_k = k + 1;
        for(int i = k + 1; i < len; ++i) {
            if(nums[i] > nums[k] && nums[i] < least_max) {
                least_max = nums[i];
                lmax_k = i;
            }
        }
        swap(nums[k], nums[lmax_k]);
        sort(nums.begin() + k + 1, nums.end());
        return true;
    }
};


