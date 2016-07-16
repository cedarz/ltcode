#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        dfs(nums);
    }
    
    void dfs(vector<int> & nums) {
        int len = nums.size();
        if(len <= 1) return;
        int x = -1;
        for(int i = len - 1; i >= 1; --i) {
            if(i - 1 >= 0 && nums[i - 1] < nums[i]) {
                x = i - 1;
                break;
            }
        }
        if(x == -1) {
            sort(nums.begin(), nums.end());
        } else {
            int s = -1;
            int m = INT_MAX;
            for(int i = x + 1; i < len; ++i) {
                if(nums[i] > nums[x] && nums[i] < m) {
                    m = nums[i];
                    s = i;
                }
            }
            swap(nums[x], nums[s]);
            sort(nums.begin() + x + 1, nums.end());
        }
    }
            
};


int main() {
    vector<int> v;
    Solution s;
    s.nextPermutation(v);
    
    return 0;
}
