#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        if(nums.empty()) return;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            switch(*it) {
                case 0: ++zero;
                        break;
                case 1: ++one;
                        break;
                case 2: ++two;
                        break;
            }
        }
        int loc[] ={0, zero, zero + one};
        int len = zero + one + two;
        int cur[] = {0, 0, 0};
        int cnt[] = {zero, one, two};
        
        for(int i = 0; i < len; ++i) {
            if(i - loc[nums[i]] < cnt[nums[i]]) {
                cur[nums[i]]++;
                continue;
            }
            
            int tmp = nums[i];
            while(i != loc[tmp] + cur[tmp]) {
                cur[tmp]++;
                swap(nums[loc[tmp] + cur[tmp] - 1], tmp);
            }
            nums[i] = tmp;
            cur[tmp]++;
        }
    }
};



int main() {
    int a[] = {1, 2, 0, 0};
    
    vector<int> v(a, a + 4);
    Solution s;
    s.sortColors(v);
    
    return 0;
}
