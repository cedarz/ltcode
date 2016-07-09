#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int num = nums.size();
        if(num < 3) return 0;
        sort(nums.begin(), nums.end());
        int minR = abs(target - nums[0] - nums[1] - nums.back());
        int res = nums[0] + nums[1] + nums.back();
        for(int i = 0; i < num - 2; ++i) {
            int j = i + 1, k = num - 1;
            int tmp = target - nums[i];
            while(j < k) {
                
                if(minR > abs(tmp - nums[j] - nums[k])) {
                    minR = abs(tmp - nums[j] - nums[k]);
                    res = nums[i] + nums[j] + nums[k];
                }
                if(tmp == nums[j] + nums[k]) {
                    return target;
                } else if(tmp > nums[j] + nums[k]) {
                    j++;
                } else {
                    k--;
                }
                    
            }
        }
        return res;
    }
};

int main() {
    //int S[] = {-1, 2, 1, -4};
    int S[] = {1,1,-1,-1,3};
    vector<int> v(S, S + 5);
    Solution s;
    cout << s.threeSumClosest(v, -1) << endl;
    return 0;
}
