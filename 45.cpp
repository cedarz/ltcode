#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        res = len - 1;
        if(len <= 1) return 0; 
        int steps = 0;
        //dfs(nums, 0, steps, len - 1);
        int cur  = 0;
        while(cur != len) {
            if(cur + nums[cur] >= len) {
                cur = len;
                steps++;
            } else {
                int tmp = 0;
                int k = 1;
                for(int i = 1; i <= nums[cur]; ++i) {
                    if(i + nums[cur + i] > tmp) {
                        k = i;
                        tmp = i + nums[cur + i];
                    }
                }
                ++steps;
                cur += k;
            }
        }
        
        return steps;
    }
    
    //void dfs(vector<int> & nums, int cur, int steps, int dst) {
        //if(steps > dst || steps > res) return;
        //if(cur == dst) {
            //res = min(steps, res);
            //return;
        //} else {
            //for(int i = 1; i <= nums[cur]; ++i) {
                //if(cur + i <= dst) {
                    //dfs(nums, cur + i, steps + 1, dst);
                //} else break;
            //}
        //}
    //}
};

int a[] = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
//int a[] = {4, 4, 4, 4};
int main() {
    cout << sizeof(a) / sizeof(int) << endl;
    vector<int> ss(a, a + sizeof(a));
    Solution s;
    clock_t start = clock();
    cout << s.jump(ss) << endl;
    clock_t end = clock();
    cout << (double(end - start)) / CLOCKS_PER_SEC << endl;
    return 0;
}
