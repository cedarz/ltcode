class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int sum = 1 << len;
        vector<vector<int> > res;
        for(int i = 0; i < sum; ++i) {
            vector<int> item;
            int x = 0;
            int tmp = i;
            while(tmp) {
                if(tmp % 2) {
                    item.push_back(nums[x]);
                } 
                tmp /= 2;
                ++x;
            }
            res.push_back(item);
        }
        return res;
    }
};


