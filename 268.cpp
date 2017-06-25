class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(nums[0]);
		for(int i = 0; i < nums.size(); ++i) {
			int tmp = nums[i];
			while(nums[tmp] != tmp) {
				swap(tmp, nums[tmp]);				
			}
		}
		
		for(int i = 0; i < nums.size(); ++i) {
			if(i != nums[i]) return i;
		}
    }
};