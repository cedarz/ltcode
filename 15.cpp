#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > v;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        v.clear();
        if(nums.size() < 3) return v;
        sort(nums.begin(), nums.end());
        dp(nums, 0, nums.size() - 1);
        return v;
    }
    void dp(vector<int> & nums, int i, int j) {
        if(j - i >= 2) {
            int tmp = -(nums[i] + nums[j]);
            vector<int>::iterator it = find(nums.begin() + i + 1, nums.begin() + j, tmp);
            if(it != nums.begin() + j) {
                vector<int> one(3, int());
                one[0] = nums[i], one[1] = *it, one[2] = nums[j];
                v.push_back(one);
            }
            int ti = i + 1, tj = j - 1;
            while(nums[ti] == nums[ti - 1] && ti < j) ++ti;
            while(nums[tj] == nums[tj + 1] && tj > i) --tj;
            for(int k = tj; k >= i + 2; ) {
                int tmp = -(nums[i] + nums[k]);
                vector<int>::iterator it = find(nums.begin() + i + 1, nums.begin() + k, tmp);
                if(it != nums.begin() + k) {
                    vector<int> one(3, int());
                    one[0] = nums[i], one[1] = *it, one[2] = nums[k];
                    v.push_back(one);
                }
                k --;
                while(nums[k] == nums[k + 1] && k >= i) --k;
            }
            for(int k = ti; k <= j - 2;) {
                int tmp = -(nums[k] + nums[j]);
                vector<int>::iterator it = find(nums.begin() + k + 1, nums.begin() + j, tmp);
                if(it != nums.begin() + j) {
                    vector<int> one(3, int());
                    one[0] = nums[k], one[1] = *it, one[2] = nums[j];
                    v.push_back(one);
                }
                ++k;
                while(nums[k] == nums[k - 1] && k <= j) ++k;
            }
            dp(nums, ti, tj);
        } 
    }
};

int main() {
    Solution s;
    
    return 0;
}

//-4, -3, -1, -1, 0, 1, 2, 2, 3, 4, 4
//f(i, j) = M(i, j) + M(i, no_j) + M(no_i, j) + f(no_i, no_j)
//slide i and j through all the same items
