#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        int n = nums.size();
        if(n < 4) return res;
        for(int i = 0; i < n - 3;) {
            int tar3 = target - nums[i];
            for(int j = i + 1; j < n - 2;) {
                int tar2 = tar3 - nums[j];
                int k = j + 1, g = n - 1;
                while(k < g) {
                    cout << tar2 " : " << nums[k] + nums[g] << endl;
                    if(tar2 == nums[k] + nums[g]) {
                        vector<int> one(4, 0);
                        one[0] = nums[i];
                        one[1] = nums[j]; 
                        one[2] = nums[k];
                        one[3] = nums[g];
                        res.push_back(one);
                        --g;
                        ++k;
                        while(nums[g] == nums[g + 1] && g > k) --g;
                        while(nums[k] == nums[k - 1] && g > k) ++k;
                    } else if(tar2 > nums[k] + nums[g]) {
                        ++k;
                    } else {
                        --g;
                    }
                    printf("%d %d %d %d : %d %d %d %d\n", i, j, k, g, nums[i], nums[j], nums[k], nums[g]);
                }
                ++j;
                while(nums[j] == nums[j - 1] && j < n) ++j;
            }
            ++i;
            while(nums[i] == nums[i - 1] && i < n) ++i;
        }        
        return res;
    }
};


