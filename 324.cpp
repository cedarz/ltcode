class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1) return;
		
		const int Len = nums.size();
		int mid = Len / 2;
		
		nth_element(nums.begin(), nums.begin() + mid, nums.end());
		for(int i = mid + 1; i < Len; ++i) {
			//swap(nums[i], nums[(i - mid) * 2 + 1]);
		}
    }
};