class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		const int L = nums.size();
        //nums.push_back(INT_MIN);
		
		for(int i = 0; i < L; ++i) {
			bool left = i - 1 == -1 ? true : nums[i] > nums[i - 1];
			bool right = i + 1 == L ? true : nums[i] > nums[i + 1];
			
			if(left && right) return i;
		}
    }
};